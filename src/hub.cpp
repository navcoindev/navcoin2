// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "bignum.h"
#include "sync.h"
#include "net.h"
#include "key.h"
#include "util.h"
#include "script.h"
#include "base58.h"
#include "protocol.h"
#include "hub.h"
#include "main.h"
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

class CHubMessage;
class CHubManager;

std::map<uint256, CHubMessage> mapHubs;
std::map<int, CHubMessage> mapHubsActive;
CHubManager hubManager;

void ProcessHub(CNode* pfrom, std::string& strCommand, CDataStream& vRecv)
{
    if(fLiteMode) return; //disable all anonsend/inode related functionality

    if (strCommand == "hub")
    {
        //LogPrintf("ProcessHub::hub\n");
        CDataStream vMsg(vRecv);
        CHubMessage hub;
        vRecv >> hub;

        if(pindexBest == NULL) return;

        uint256 hash = hub.GetHash();
        if(mapHubs.count(hash) && mapHubsActive.count(hub.nHubID)) {
            if(mapHubsActive[hub.nHubID].nTimeSigned >= hub.nTimeSigned){
                if(fDebug) LogPrintf("hub - seen %s block %d \n", hash.ToString().c_str(), pindexBest->nHeight);
                return;
            } else {
                if(fDebug) LogPrintf("hub - got updated hub %s block %d \n", hash.ToString().c_str(), pindexBest->nHeight);
            }
        }

        LogPrintf("hub - new %s ID %d Time %d bestHeight %d\n", hash.ToString().c_str(), hub.nHubID, hub.nValue, pindexBest->nHeight);

        if(!hubManager.CheckSignature(hub)){
            LogPrintf("hub - invalid signature\n");
            Misbehaving(pfrom->GetId(), 100);
            return;
        }

        mapHubs[hash] = hub;
        mapHubsActive[hub.nHubID] = hub;
        hubManager.Relay(hub);

        //does a task if needed
        ExecuteHub(hub.nHubID, hub.nValue);
    }
    if (strCommand == "gethubs")
    {
        std::map<int, CHubMessage>::iterator it = mapHubsActive.begin();

        while(it != mapHubsActive.end()) {
            pfrom->PushMessage("hub", it->second);
            it++;
        }
    }

}

// grab the hub, otherwise say it's off
bool IsHubActive(int nHubID)
{
    int64_t r = 0;

    if(mapHubsActive.count(nHubID)){
        r = mapHubsActive[nHubID].nValue;
    } else {
        if(nHubID == HUB_1_INODE_PAYMENTS_ENFORCEMENT) r = HUB_1_INODE_PAYMENTS_ENFORCEMENT_DEFAULT;
        if(nHubID == HUB_2_MAX_VALUE) r = HUB_2_MAX_VALUE_DEFAULT;
        if(nHubID == HUB_3_REPLAY_BLOCKS) r = HUB_3_REPLAY_BLOCKS_DEFAULT;

        if(r == 0 && fDebug) LogPrintf("GetHub::Unknown Hub %d\n", nHubID);
    }
    if(r == 0) r = 4070908800; //return 2099-1-1 by default

    return r < GetTime();
}

// grab the value of the hub on the network, or the default
int GetHubValue(int nHubID)
{
    int r = 0;

    if(mapHubsActive.count(nHubID)){
        r = mapHubsActive[nHubID].nValue;
    } else {
        if(nHubID == HUB_1_INODE_PAYMENTS_ENFORCEMENT) r = HUB_1_INODE_PAYMENTS_ENFORCEMENT_DEFAULT;
        if(nHubID == HUB_2_MAX_VALUE) r = HUB_2_MAX_VALUE_DEFAULT;
        if(nHubID == HUB_3_REPLAY_BLOCKS) r = HUB_3_REPLAY_BLOCKS_DEFAULT;

        if(r == 0 && fDebug) LogPrintf("GetHub::Unknown Hub %d\n", nHubID);
    }

    return r;
}

void ExecuteHub(int nHubID, int nValue)
{
    //replay and process blocks (to sync to the longest chain after disabling hubs)
    //if(nHubID == HUB_3_REPLAY_BLOCKS){
        //DisconnectBlocksAndReprocess(nValue);
    //}
}


bool CHubManager::CheckSignature(CHubMessage& hub)
{
    //note: need to investigate why this is failing
    std::string strMessage = boost::lexical_cast<std::string>(hub.nHubID) + boost::lexical_cast<std::string>(hub.nValue) + boost::lexical_cast<std::string>(hub.nTimeSigned);
    std::string strPubKey = strMainPubKey;
    CPubKey pubkey(ParseHex(strPubKey));

    std::string errorMessage = "";
    if(!anonSendSigner.VerifyMessage(pubkey, hub.vchSig, strMessage, errorMessage)){
        return false;
    }

    return true;
}

bool CHubManager::Sign(CHubMessage& hub)
{
    std::string strMessage = boost::lexical_cast<std::string>(hub.nHubID) + boost::lexical_cast<std::string>(hub.nValue) + boost::lexical_cast<std::string>(hub.nTimeSigned);

    CKey key2;
    CPubKey pubkey2;
    std::string errorMessage = "";

    if(!anonSendSigner.SetKey(strMasterPrivKey, errorMessage, key2, pubkey2))
    {
        LogPrintf("CNodePayments::Sign - ERROR: Invalid inodeprivkey: '%s'\n", errorMessage.c_str());
        return false;
    }

    if(!anonSendSigner.SignMessage(strMessage, errorMessage, hub.vchSig, key2)) {
        LogPrintf("CInodePayments::Sign - Sign message failed");
        return false;
    }

    if(!anonSendSigner.VerifyMessage(pubkey2, hub.vchSig, strMessage, errorMessage)) {
        LogPrintf("CInodePayments::Sign - Verify message failed");
        return false;
    }

    return true;
}

bool CHubManager::UpdateHub(int nHubID, int64_t nValue)
{

    CHubMessage msg;
    msg.nHubID = nHubID;
    msg.nValue = nValue;
    msg.nTimeSigned = GetTime();

    if(Sign(msg)){
        Relay(msg);
        mapHubs[msg.GetHash()] = msg;
        mapHubsActive[nHubID] = msg;
        return true;
    }

    return false;
}

void CHubManager::Relay(CHubMessage& msg)
{
    CInv inv(MSG_HUB, msg.GetHash());

    vector<CInv> vInv;
    vInv.push_back(inv);
    LOCK(cs_vNodes);
    BOOST_FOREACH(CNode* pnode, vNodes){
        pnode->PushMessage("inv", vInv);
    }
}

bool CHubManager::SetPrivKey(std::string strPrivKey)
{
    CHubMessage msg;

    // Test signing successful, proceed
    strMasterPrivKey = strPrivKey;

    Sign(msg);

    if(CheckSignature(msg)){
        LogPrintf("CHubManager::SetPrivKey - Successfully initialized as hub signer\n");
        return true;
    } else {
        return false;
    }
}

int CHubManager::GetHubIDByName(std::string strName)
{
    if(strName == "HUB_1_INODE_PAYMENTS_ENFORCEMENT") return HUB_1_INODE_PAYMENTS_ENFORCEMENT;
    if(strName == "HUB_2_MAX_VALUE") return HUB_2_MAX_VALUE;
    if(strName == "HUB_3_REPLAY_BLOCKS") return HUB_3_REPLAY_BLOCKS;

    return -1;
}

std::string CHubManager::GetHubNameByID(int id)
{
    if(id == HUB_1_INODE_PAYMENTS_ENFORCEMENT) return "HUB_1_INODE_PAYMENTS_ENFORCEMENT";
    if(id == HUB_2_MAX_VALUE) return "HUB_2_MAX_VALUE";
    if(id == HUB_3_REPLAY_BLOCKS) return "HUB_3_REPLAY_BLOCKS";

    return "Unknown";
}
