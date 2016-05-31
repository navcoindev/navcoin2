// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef INODE_H
#define INODE_H

#include "uint256.h"
#include "uint256.h"
#include "sync.h"
#include "net.h"
#include "key.h"
#include "util.h"
#include "base58.h"
#include "main.h"
#include "timedata.h"
#include "script.h"

class CINode;
class CInodePayments;
class uint256;

#define INODE_NOT_PROCESSED               0 // initial state
#define INODE_IS_CAPABLE                  1
#define INODE_NOT_CAPABLE                 2
#define INODE_STOPPED                     3
#define INODE_INPUT_TOO_NEW               4
#define INODE_PORT_NOT_OPEN               6
#define INODE_PORT_OPEN                   7
#define INODE_SYNC_IN_PROCESS             8
#define INODE_REMOTELY_ENABLED            9

#define INODE_MIN_CONFIRMATIONS           7
#define INODE_MIN_DSEEP_SECONDS           (15*60)
#define INODE_MIN_DSEE_SECONDS            (1*60)
#define INODE_PING_SECONDS                (10) //(1*60)
#define INODE_EXPIRATION_SECONDS          (65*60)
#define INODE_REMOVAL_SECONDS             (70*60)

using namespace std;

class CInodePaymentWinner;

extern CCriticalSection cs_inodes;
extern std::vector<CINode> vecInodes;
extern CInodePayments inodePayments;
extern std::vector<CTxIn> vecInodeAskedFor;
extern map<uint256, CInodePaymentWinner> mapSeenInodeVotes;
extern map<int64_t, uint256> mapCacheBlockHashes;


// manage the inode connections
void ProcessInodeConnections();
int CountInodesAboveProtocol(int protocolVersion);


void ProcessMessageInode(CNode* pfrom, std::string& strCommand, CDataStream& vRecv);

//
// The Inode Class. For managing the anonsend process. It contains the input of the 1000NAV, signature to prove
// it's the one who own that ip address and code for calculating the payment election.
//
class CINode
{
public:
	static int minProtoVersion;
    CService addr;
    CTxIn vin;
    int64_t lastTimeSeen;
    CPubKey pubkey;
    CPubKey pubkey2;
    std::vector<unsigned char> sig;
    int64_t now; //dsee message times
    int64_t lastDseep;
    int cacheInputAge;
    int cacheInputAgeBlock;
    int enabled;
    bool unitTest;
    bool allowFreeTx;
    int protocolVersion;

    //the dsq count from the last dsq broadcast of this node
    int64_t nLastDsq;

    CINode(CService newAddr, CTxIn newVin, CPubKey newPubkey, std::vector<unsigned char> newSig, int64_t newNow, CPubKey newPubkey2, int protocolVersionIn)
    {
        addr = newAddr;
        vin = newVin;
        pubkey = newPubkey;
        pubkey2 = newPubkey2;
        sig = newSig;
        now = newNow;
        enabled = 1;
        lastTimeSeen = 0;
        unitTest = false;
        cacheInputAge = 0;
        cacheInputAgeBlock = 0;
        nLastDsq = 0;
        lastDseep = 0;
        allowFreeTx = true;
        protocolVersion = protocolVersionIn;
    }

    uint256 CalculateScore(int mod=1, int64_t nBlockHeight=0);

    void UpdateLastSeen(int64_t override=0)
    {
        if(override == 0){
            lastTimeSeen = GetAdjustedTime();
        } else {
            lastTimeSeen = override;
        }
    }

    inline uint64_t SliceHash(uint256& hash, int slice)
    {
        uint64_t n = 0;
        memcpy(&n, &hash+slice*64, 64);
        return n;
    }

    void Check();

    bool UpdatedWithin(int seconds)
    {
        // LogPrintf("UpdatedWithin %d, %d --  %d \n", GetAdjustedTime() , lastTimeSeen, (GetAdjustedTime() - lastTimeSeen) < seconds);

        return (GetAdjustedTime() - lastTimeSeen) < seconds;
    }

    void Disable()
    {
        lastTimeSeen = 0;
    }

    bool IsEnabled()
    {
        return enabled == 1;
    }

    int GetInodeInputAge()
    {
        if(pindexBest == NULL) return 0;

        if(cacheInputAge == 0){
            cacheInputAge = GetInputAge(vin);
            cacheInputAgeBlock = pindexBest->nHeight;
        }

        return cacheInputAge+(pindexBest->nHeight-cacheInputAgeBlock);
    }
};


// Get the current winner for this block
int GetCurrentINode(int mod=1, int64_t nBlockHeight=0, int minProtocol=CINode::minProtoVersion);

int GetInodeByVin(CTxIn& vin);
int GetInodeRank(CTxIn& vin, int64_t nBlockHeight=0, int minProtocol=CINode::minProtoVersion);
int GetInodeByRank(int findRank, int64_t nBlockHeight=0, int minProtocol=CINode::minProtoVersion);


// for storing the winning payments
class CInodePaymentWinner
{
public:
    int nBlockHeight;
    CTxIn vin;
    CScript payee;
    std::vector<unsigned char> vchSig;
    uint64_t score;

    CInodePaymentWinner() {
        nBlockHeight = 0;
        score = 0;
        vin = CTxIn();
        payee = CScript();
    }

    uint256 GetHash(){
        uint256 n2 = Hash(BEGIN(nBlockHeight), END(nBlockHeight));
        uint256 n3 = vin.prevout.hash > n2 ? (vin.prevout.hash - n2) : (n2 - vin.prevout.hash);

        return n3;
    }

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion){
	unsigned int nSerSize = 0;
        READWRITE(nBlockHeight);
        READWRITE(payee);
        READWRITE(vin);
        READWRITE(score);
        READWRITE(vchSig);
     }
};

//
// Inode Payments Class
// Keeps track of who should get paid for which blocks
//

class CInodePayments
{
private:
    std::vector<CInodePaymentWinner> vWinning;
    int nSyncedFromPeer;
    std::string strMasterPrivKey;
    std::string strTestPubKey;
    std::string strMainPubKey;
    bool enabled;

public:

    CInodePayments() {
        strMainPubKey = "04e8e12311dbdd6689e60e33828178975579b7f6f53217bcfaaa2c997f3d20e09e0134202bd88b88933d311e7b6de70ab90b322757d5d3df673c20af9dcb65cc64";
        strTestPubKey = "04e8e12311dbdd6689e60e33828178975579b7f6f53217bcfaaa2c997f3d20e09e0134202bd88b88933d311e7b6de70ab90b322757d5d3df673c20af9dcb65cc64";
        enabled = false;
    }

    bool SetPrivKey(std::string strPrivKey);
    bool CheckSignature(CInodePaymentWinner& winner);
    bool Sign(CInodePaymentWinner& winner);

    // Deterministically calculate a given "score" for a inode depending on how close it's hash is
    // to the blockHeight. The further away they are the better, the furthest will win the election
    // and get paid this block
    //

    uint64_t CalculateScore(uint256 blockHash, CTxIn& vin);
    bool GetWinningInode(int nBlockHeight, CTxIn& vinOut);
    bool AddWinningInode(CInodePaymentWinner& winner);
    bool ProcessBlock(int nBlockHeight);
    void Relay(CInodePaymentWinner& winner);
    void Sync(CNode* node);
    void CleanPaymentList();
    int LastPayment(CINode& mn);

    //slow
    bool GetBlockPayee(int nBlockHeight, CScript& payee);
};



#endif
