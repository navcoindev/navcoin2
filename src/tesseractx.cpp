


#include "uint256.h"
#include "sync.h"
#include "net.h"
#include "key.h"
#include "util.h"
#include "base58.h"
#include "protocol.h"
#include "tesseractx.h"
#include "inode.h"
#include "activeinode.h"
#include "anonsend.h"
#include "hub.h"
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

std::map<uint256, CTransaction> mapTxLockReq;
std::map<uint256, CTransaction> mapTxLockReqRejected;
std::map<uint256, CConsensusVote> mapTxLockVote;
std::map<uint256, CTransactionLock> mapTxLocks;
std::map<COutPoint, uint256> mapLockedInputs;
std::map<uint256, int64_t> mapUnknownVotes; //track votes with no tx for DOS
int nCompleteTXLocks;

//txlock - Locks transaction
//
//step 1.) Broadcast intention to lock transaction inputs, "txlreg", CTransaction
//step 2.) Top 10 inodes, open connect to top 1 inode. Send "txvote", CTransaction, Signature, Approve
//step 3.) Top 1 inode, waits for 10 messages. Upon success, sends "txlock'

void ProcessMessageTesseractX(CNode* pfrom, std::string& strCommand, CDataStream& vRecv)
{
    if(fLiteMode) return; //disable all anonsend/inode related functionality
    if(!IsHubActive(HUB_1_INODE_PAYMENTS_ENFORCEMENT)) return;

    if (strCommand == "txlreq")
    {
        //LogPrintf("ProcessMessageTesseractX::txlreq\n");
        CDataStream vMsg(vRecv);
        CTransaction tx;
        vRecv >> tx;

        CInv inv(MSG_TXLOCK_REQUEST, tx.GetHash());
        pfrom->AddInventoryKnown(inv);

        if(mapTxLockReq.count(tx.GetHash()) || mapTxLockReqRejected.count(tx.GetHash())){
            return;
        }

        if(!IsTSXTXValid(tx)){
            return;
        }

        BOOST_FOREACH(const CTxOut o, tx.vout){
            if(!o.scriptPubKey.IsNormalPaymentScript()){
                printf ("ProcessMessageTesseractX::txlreq - Invalid Script %s\n", tx.ToString().c_str());
                return;
            }
        }

        int nBlockHeight = CreateNewLock(tx);

        bool fMissingInputs = false;
        CValidationState state;


        //if (AcceptToMemoryPool(mempool, state, tx, true, &fMissingInputs))
        if (AcceptToMemoryPool(mempool, tx, true, &fMissingInputs))
        {
            vector<CInv> vInv;
            vInv.push_back(inv);
            LOCK(cs_vNodes);
            BOOST_FOREACH(CNode* pnode, vNodes)
                pnode->PushMessage("inv", vInv);

            DoConsensusVote(tx, nBlockHeight);

            mapTxLockReq.insert(make_pair(tx.GetHash(), tx));

            LogPrintf("ProcessMessageTesseractX::txlreq - Transaction Lock Request: %s %s : accepted %s\n",
                pfrom->addr.ToString().c_str(), pfrom->cleanSubVer.c_str(),
                tx.GetHash().ToString().c_str()
            );

            return;

        } else {
            mapTxLockReqRejected.insert(make_pair(tx.GetHash(), tx));

            // can we get the conflicting transaction as proof?

            LogPrintf("ProcessMessageTesseractX::txlreq - Transaction Lock Request: %s %s : rejected %s\n",
                pfrom->addr.ToString().c_str(), pfrom->cleanSubVer.c_str(),
                tx.GetHash().ToString().c_str()
            );

            BOOST_FOREACH(const CTxIn& in, tx.vin){
                if(!mapLockedInputs.count(in.prevout)){
                    mapLockedInputs.insert(make_pair(in.prevout, tx.GetHash()));
                }
            }

            // resolve conflicts
            std::map<uint256, CTransactionLock>::iterator i = mapTxLocks.find(tx.GetHash());
            if (i != mapTxLocks.end()){
                //we only care if we have a complete tx lock
                if((*i).second.CountSignatures() >= TESSERACTX_SIGNATURES_REQUIRED){
                    if(!CheckForConflictingLocks(tx)){
                        LogPrintf("ProcessMessageTesseractX::txlreq - Found Existing Complete TSX Lock\n");

                        CValidationState state;
                        //DisconnectBlockAndInputs(state, tx);
                        mapTxLockReq.insert(make_pair(tx.GetHash(), tx));
                    }
                }
            }

            return;
        }
    }
    else if (strCommand == "txlvote") //TesseractX Lock Consensus Votes
    {
        CConsensusVote ctx;
        vRecv >> ctx;

        CInv inv(MSG_TXLOCK_VOTE, ctx.GetHash());
        pfrom->AddInventoryKnown(inv);

        if(mapTxLockVote.count(ctx.GetHash())){
            return;
        }

        mapTxLockVote.insert(make_pair(ctx.GetHash(), ctx));

        if(ProcessConsensusVote(ctx)){
            //Spam/Dos protection
            /*
                Nodes will sometimes propagate votes before the transaction is known to the client.
                This tracks those messages and allows it at the same rate of the rest of the network, if
                a peer violates it, it will simply be ignored
            */
            if(!mapTxLockReq.count(ctx.txHash) && !mapTxLockReqRejected.count(ctx.txHash)){
                if(!mapUnknownVotes.count(ctx.vinInode.prevout.hash)){
                    mapUnknownVotes[ctx.vinInode.prevout.hash] = GetTime()+(60*10);
                }

                if(mapUnknownVotes[ctx.vinInode.prevout.hash] > GetTime() &&
                    mapUnknownVotes[ctx.vinInode.prevout.hash] - GetAverageVoteTime() > 60*10){
                        LogPrintf("ProcessMessageTesseractX::txlreq - inode is spamming transaction votes: %s %s\n",
                            ctx.vinInode.ToString().c_str(),
                            ctx.txHash.ToString().c_str()
                        );
                        return;
                } else {
                    mapUnknownVotes[ctx.vinInode.prevout.hash] = GetTime()+(60*10);
                }
            }
            vector<CInv> vInv;
            vInv.push_back(inv);
            LOCK(cs_vNodes);
            BOOST_FOREACH(CNode* pnode, vNodes)
                pnode->PushMessage("inv", vInv);

        }

        return;
    }
}

bool IsTSXTXValid(const CTransaction& txCollateral){
    if(txCollateral.vout.size() < 1) return false;
    if(txCollateral.nLockTime != 0) return false;

    int64_t nValueIn = 0;
    int64_t nValueOut = 0;
    bool missingTx = false;

    BOOST_FOREACH(const CTxOut o, txCollateral.vout)
        nValueOut += o.nValue;

    BOOST_FOREACH(const CTxIn i, txCollateral.vin){
        CTransaction tx2;
        uint256 hash;
        //if(GetTransaction(i.prevout.hash, tx2, hash, true)){
	if(GetTransaction(i.prevout.hash, tx2, hash)){
            if(tx2.vout.size() > i.prevout.n) {
                nValueIn += tx2.vout[i.prevout.n].nValue;
            }
        } else{
            missingTx = true;
        }
    }

    if(nValueOut > GetHubValue(HUB_2_MAX_VALUE)*COIN){
        if(fDebug) LogPrintf ("IsTSXTXValid - Transaction value too high - %s\n", txCollateral.ToString().c_str());
        return false;
    }

    if(missingTx){
        if(fDebug) LogPrintf ("IsTSXTXValid - Unknown inputs in TSX transaction - %s\n", txCollateral.ToString().c_str());
        /*
            This happens sometimes for an unknown reason, so we'll return that it's a valid transaction.
            If someone submits an invalid transaction it will be rejected by the network anyway and this isn't
            very common, but we don't want to block TSX just because the client can't figure out the fee.
        */
        return true;
    }

    if(nValueIn-nValueOut < COIN*0.01) {
        if(fDebug) LogPrintf ("IsTSXTXValid - did not include enough fees in transaction %d\n%s\n", nValueOut-nValueIn, txCollateral.ToString().c_str());
        return false;
    }

    return true;
}

int64_t CreateNewLock(CTransaction tx)
{

    int64_t nTxAge = 0;
    BOOST_REVERSE_FOREACH(CTxIn i, tx.vin){
        nTxAge = GetInputAge(i);
        if(nTxAge < 6)
        {
            LogPrintf("CreateNewLock - Transaction not found / too new: %d / %s\n", nTxAge, tx.GetHash().ToString().c_str());
            return 0;
        }
    }

    /*
        Use a blockheight newer than the input.
        This prevents attackers from using transaction mallibility to predict which inodes
        they'll use.
    */
    int nBlockHeight = (pindexBest->nHeight - nTxAge)+4;

    if (!mapTxLocks.count(tx.GetHash())){
        LogPrintf("CreateNewLock - New Transaction Lock %s !\n", tx.GetHash().ToString().c_str());

        CTransactionLock newLock;
        newLock.nBlockHeight = nBlockHeight;
        newLock.nExpiration = GetTime()+(60*60); //locks expire after 15 minutes (6 confirmations)
        newLock.nTimeout = GetTime()+(60*5);
        newLock.txHash = tx.GetHash();
        mapTxLocks.insert(make_pair(tx.GetHash(), newLock));
    } else {
        mapTxLocks[tx.GetHash()].nBlockHeight = nBlockHeight;
        if(fDebug) LogPrintf("CreateNewLock - Transaction Lock Exists %s !\n", tx.GetHash().ToString().c_str());
    }

    return nBlockHeight;
}

// check if we need to vote on this transaction
void DoConsensusVote(CTransaction& tx, int64_t nBlockHeight)
{
    if(!fINode) return;

    int n = GetInodeRank(activeInode.vin, nBlockHeight, MIN_TESSERACTX_PROTO_VERSION);

    if(n == -1)
    {
        if(fDebug) LogPrintf("TesseractX::DoConsensusVote - Unknown Inode\n");
        return;
    }

    if(n > TESSERACTX_SIGNATURES_TOTAL)
    {
        if(fDebug) LogPrintf("TesseractX::DoConsensusVote - Inode not in the top %d (%d)\n", TESSERACTX_SIGNATURES_TOTAL, n);
        return;
    }
    /*
        nBlockHeight calculated from the transaction is the authoritive source
    */

    if(fDebug) LogPrintf("TesseractX::DoConsensusVote - In the top %d (%d)\n", TESSERACTX_SIGNATURES_TOTAL, n);

    CConsensusVote ctx;
    ctx.vinInode = activeInode.vin;
    ctx.txHash = tx.GetHash();
    ctx.nBlockHeight = nBlockHeight;
    if(!ctx.Sign()){
        LogPrintf("TesseractX::DoConsensusVote - Failed to sign consensus vote\n");
        return;
    }
    if(!ctx.SignatureValid()) {
        LogPrintf("TesseractX::DoConsensusVote - Signature invalid\n");
        return;
    }

    mapTxLockVote[ctx.GetHash()] = ctx;

    CInv inv(MSG_TXLOCK_VOTE, ctx.GetHash());

    vector<CInv> vInv;
    vInv.push_back(inv);
    LOCK(cs_vNodes);
    BOOST_FOREACH(CNode* pnode, vNodes){
        pnode->PushMessage("inv", vInv);
    }

}

//received a consensus vote
bool ProcessConsensusVote(CConsensusVote& ctx)
{
    int n = GetInodeRank(ctx.vinInode, ctx.nBlockHeight, MIN_TESSERACTX_PROTO_VERSION);

    int x = GetInodeByVin(ctx.vinInode);
    if(x != -1){
        if(fDebug) LogPrintf("TesseractX::ProcessConsensusVote - Inode ADDR %s %d\n", vecInodes[x].addr.ToString().c_str(), n);
    }

    if(n == -1)
    {
        //can be caused by past versions trying to vote with an invalid protocol
        if(fDebug) LogPrintf("TesseractX::ProcessConsensusVote - Unknown Inode\n");
        return false;
    }

    if(n > TESSERACTX_SIGNATURES_TOTAL)
    {
        if(fDebug) LogPrintf("TesseractX::ProcessConsensusVote - Inode not in the top %d (%d) - %s\n", TESSERACTX_SIGNATURES_TOTAL, n, ctx.GetHash().ToString().c_str());
        return false;
    }

    if(!ctx.SignatureValid()) {
        LogPrintf("TesseractX::ProcessConsensusVote - Signature invalid\n");
        //don't ban, it could just be a non-synced inode
        return false;
    }

    if (!mapTxLocks.count(ctx.txHash)){
        LogPrintf("TesseractX::ProcessConsensusVote - New Transaction Lock %s !\n", ctx.txHash.ToString().c_str());

        CTransactionLock newLock;
        newLock.nBlockHeight = 0;
        newLock.nExpiration = GetTime()+(60*60);
        newLock.nTimeout = GetTime()+(60*5);
        newLock.txHash = ctx.txHash;
        mapTxLocks.insert(make_pair(ctx.txHash, newLock));
    } else {
        if(fDebug) LogPrintf("TesseractX::ProcessConsensusVote - Transaction Lock Exists %s !\n", ctx.txHash.ToString().c_str());
    }

    //compile consessus vote
    std::map<uint256, CTransactionLock>::iterator i = mapTxLocks.find(ctx.txHash);
    if (i != mapTxLocks.end()){
        (*i).second.AddSignature(ctx);

#ifdef ENABLE_WALLET
        if(pwalletMain){
            //when we get back signatures, we'll count them as requests. Otherwise the client will think it didn't propagate.
            if(pwalletMain->mapRequestCount.count(ctx.txHash))
                pwalletMain->mapRequestCount[ctx.txHash]++;
        }
#endif

        if(fDebug) LogPrintf("TesseractX::ProcessConsensusVote - Transaction Lock Votes %d - %s !\n", (*i).second.CountSignatures(), ctx.GetHash().ToString().c_str());

        if((*i).second.CountSignatures() >= TESSERACTX_SIGNATURES_REQUIRED){
            if(fDebug) LogPrintf("TesseractX::ProcessConsensusVote - Transaction Lock Is Complete %s !\n", (*i).second.GetHash().ToString().c_str());

            CTransaction& tx = mapTxLockReq[ctx.txHash];
            if(!CheckForConflictingLocks(tx)){

#ifdef ENABLE_WALLET
                if(pwalletMain){
                    pwalletMain->UpdatedTransaction((*i).second.txHash);
                        nCompleteTXLocks++;
                    
                }
#endif

                if(mapTxLockReq.count(ctx.txHash)){
                    BOOST_FOREACH(const CTxIn& in, tx.vin){
                        if(!mapLockedInputs.count(in.prevout)){
                            mapLockedInputs.insert(make_pair(in.prevout, ctx.txHash));
                        }
                    }
                }

                // resolve conflicts

                //if this tx lock was rejected, we need to remove the conflicting blocks
                if(mapTxLockReqRejected.count((*i).second.txHash)){
                    CValidationState state;
                    //DisconnectBlockAndInputs(state, mapTxLockReqRejected[(*i).second.txHash]);
                }
            }
        }
        return true;
    }


    return false;
}

bool CheckForConflictingLocks(CTransaction& tx)
{
    /*
        It's possible (very unlikely though) to get 2 conflicting transaction locks approved by the network.
        In that case, they will cancel each other out.

        Blocks could have been rejected during this time, which is OK. After they cancel out, the client will
        rescan the blocks and find they're acceptable and then take the chain with the most work.
    */
    BOOST_FOREACH(const CTxIn& in, tx.vin){
        if(mapLockedInputs.count(in.prevout)){
            if(mapLockedInputs[in.prevout] != tx.GetHash()){
                LogPrintf("TesseractX::CheckForConflictingLocks - found two complete conflicting locks - removing both. %s %s", tx.GetHash().ToString().c_str(), mapLockedInputs[in.prevout].ToString().c_str());
                if(mapTxLocks.count(tx.GetHash())) mapTxLocks[tx.GetHash()].nExpiration = GetTime();
                if(mapTxLocks.count(mapLockedInputs[in.prevout])) mapTxLocks[mapLockedInputs[in.prevout]].nExpiration = GetTime();
                return true;
            }
        }
    }

    return false;
}

int64_t GetAverageVoteTime()
{
    std::map<uint256, int64_t>::iterator it = mapUnknownVotes.begin();
    int64_t total = 0;
    int64_t count = 0;

    while(it != mapUnknownVotes.end()) {
        total+= it->second;
        count++;
        it++;
    }

    return total / count;
}

void CleanTransactionLocksList()
{
    if(pindexBest == NULL) return;

    std::map<uint256, CTransactionLock>::iterator it = mapTxLocks.begin();

    while(it != mapTxLocks.end()) {
        if(GetTime() > it->second.nExpiration){ //keep them for an hour
            LogPrintf("Removing old transaction lock %s\n", it->second.txHash.ToString().c_str());

            if(mapTxLockReq.count(it->second.txHash)){
                CTransaction& tx = mapTxLockReq[it->second.txHash];

                BOOST_FOREACH(const CTxIn& in, tx.vin)
                    mapLockedInputs.erase(in.prevout);

                mapTxLockReq.erase(it->second.txHash);
                mapTxLockReqRejected.erase(it->second.txHash);

                BOOST_FOREACH(CConsensusVote& v, it->second.vecConsensusVotes)
                    mapTxLockVote.erase(v.GetHash());
            }

            mapTxLocks.erase(it++);
        } else {
            it++;
        }
    }

}

uint256 CConsensusVote::GetHash() const
{
    return vinInode.prevout.hash + vinInode.prevout.n + txHash;
}


bool CConsensusVote::SignatureValid()
{
    std::string errorMessage;
    std::string strMessage = txHash.ToString().c_str() + boost::lexical_cast<std::string>(nBlockHeight);
    //LogPrintf("verify strMessage %s \n", strMessage.c_str());

    int n = GetInodeByVin(vinInode);

    if(n == -1)
    {
        LogPrintf("TesseractX::CConsensusVote::SignatureValid() - Unknown INode\n");
        return false;
    }

    //LogPrintf("verify addr %s \n", vecInodes[0].addr.ToString().c_str());
    //LogPrintf("verify addr %s \n", vecInodes[1].addr.ToString().c_str());
    //LogPrintf("verify addr %d %s \n", n, vecInodes[n].addr.ToString().c_str());

    CScript pubkey;
    pubkey =GetScriptForDestination(vecInodes[n].pubkey2.GetID());
    CTxDestination address1;
    ExtractDestination(pubkey, address1);
    CBitcoinAddress address2(address1);
    //LogPrintf("verify pubkey2 %s \n", address2.ToString().c_str());

    if(!anonSendSigner.VerifyMessage(vecInodes[n].pubkey2, vchINodeSignature, strMessage, errorMessage)) {
        LogPrintf("TesseractX::CConsensusVote::SignatureValid() - Verify message failed\n");
        return false;
    }

    return true;
}

bool CConsensusVote::Sign()
{
    std::string errorMessage;

    CKey key2;
    CPubKey pubkey2;
    std::string strMessage = txHash.ToString().c_str() + boost::lexical_cast<std::string>(nBlockHeight);
    //LogPrintf("signing strMessage %s \n", strMessage.c_str());
    //LogPrintf("signing privkey %s \n", strINodePrivKey.c_str());

    if(!anonSendSigner.SetKey(strINodePrivKey, errorMessage, key2, pubkey2))
    {
        LogPrintf("CActiveInode::RegisterAsINode() - ERROR: Invalid inodeprivkey: '%s'\n", errorMessage.c_str());
        return false;
    }

    CScript pubkey;
    pubkey =GetScriptForDestination(pubkey2.GetID());
    CTxDestination address1;
    ExtractDestination(pubkey, address1);
    CBitcoinAddress address2(address1);
    //LogPrintf("signing pubkey2 %s \n", address2.ToString().c_str());

    if(!anonSendSigner.SignMessage(strMessage, errorMessage, vchINodeSignature, key2)) {
        LogPrintf("CActiveInode::RegisterAsNode() - Sign message failed");
        return false;
    }

    if(!anonSendSigner.VerifyMessage(pubkey2, vchINodeSignature, strMessage, errorMessage)) {
        LogPrintf("CActiveInode::RegisterAsINode() - Verify message failed");
        return false;
    }

    return true;
}


bool CTransactionLock::SignaturesValid()
{

    BOOST_FOREACH(CConsensusVote vote, vecConsensusVotes)
    {
        int n = GetInodeRank(vote.vinInode, vote.nBlockHeight, MIN_TESSERACTX_PROTO_VERSION);

        if(n == -1)
        {
            LogPrintf("TesseractX::DoConsensusVote - Unknown Inode\n");
            return false;
        }

        if(n > TESSERACTX_SIGNATURES_TOTAL)
        {
            LogPrintf("TesseractX::DoConsensusVote - Inode not in the top %s\n", TESSERACTX_SIGNATURES_TOTAL);
            return false;
        }

        if(!vote.SignatureValid()){
            LogPrintf("TesseractX::CTransactionLock::SignaturesValid - Signature not valid\n");
            return false;
        }
    }

    return true;
}

void CTransactionLock::AddSignature(CConsensusVote& cv)
{
    vecConsensusVotes.push_back(cv);
}

int CTransactionLock::CountSignatures()
{
    /*
        Only count signatures where the BlockHeight matches the transaction's blockheight.
        The votes have no proof it's the correct blockheight
    */

    if(nBlockHeight == 0) return -1;

    int n = 0;
    BOOST_FOREACH(CConsensusVote v, vecConsensusVotes){
        if(v.nBlockHeight == nBlockHeight){
            n++;
        }
    }
    return n;
}
