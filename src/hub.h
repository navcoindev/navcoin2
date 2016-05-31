// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef HUB_H
#define HUB_H

#include "bignum.h"
#include "sync.h"
#include "net.h"
#include "key.h"

#include "util.h"
#include "script.h"
#include "base58.h"
#include "main.h"

using namespace std;
using namespace boost;

// Don't ever reuse these IDs for other hubs
#define HUB_1_INODE_PAYMENTS_ENFORCEMENT               10000
#define HUB_2_MAX_VALUE                                     10002
#define HUB_3_REPLAY_BLOCKS                                 10003
#define HUB_4_NOTUSED                                       10004


#define HUB_1_INODE_PAYMENTS_ENFORCEMENT_DEFAULT       2428537599  //2015-4-8 23:59:59 GMT
#define HUB_2_MAX_VALUE_DEFAULT                             500        //500 NAV 
#define HUB_3_REPLAY_BLOCKS_DEFAULT                         0
#define HUB_4_RECONVERGE_DEFAULT                            1420070400  //2047-1-1

class CHubMessage;
class CHubManager;

#include "bignum.h"
#include "net.h"
#include "key.h"
#include "util.h"
#include "protocol.h"
#include "anonsend.h"
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

extern std::map<uint256, CHubMessage> mapHubs;
extern std::map<int, CHubMessage> mapHubsActive;
extern CHubManager hubManager;

void ProcessHub(CNode* pfrom, std::string& strCommand, CDataStream& vRecv);
int GetHubValue(int nHubID);
bool IsHubActive(int nHubID);
void ExecuteHub(int nHubID, int nValue);

//
// Hub Class
// Keeps track of all of the network hub settings
//

class CHubMessage
{
public:
    std::vector<unsigned char> vchSig;
    int nHubID;
    int64_t nValue;
    int64_t nTimeSigned;

    uint256 GetHash(){
        uint256 n = Hash(BEGIN(nHubID), END(nTimeSigned));
        return n;
    }

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion) {
	unsigned int nSerSize = 0;
        READWRITE(nHubID);
        READWRITE(nValue);
        READWRITE(nTimeSigned);
        READWRITE(vchSig);
	}
};


class CHubManager
{
private:
    std::vector<unsigned char> vchSig;

    std::string strMasterPrivKey;
    std::string strTestPubKey;
    std::string strMainPubKey;

public:

    CHubManager() {
        strMainPubKey = "04e8e12311dbdd6689e60e33828178975579b7f6f53217bcfaaa2c997f3d20e09e0134202bd88b88933d311e7b6de70ab90b322757d5d3df673c20af9dcb65cc64";
        strTestPubKey = "04e8e12311dbdd6689e60e33828178975579b7f6f53217bcfaaa2c997f3d20e09e0134202bd88b88933d311e7b6de70ab90b322757d5d3df673c20af9dcb65cc64";
    }

    std::string GetHubNameByID(int id);
    int GetHubIDByName(std::string strName);
    bool UpdateHub(int nHubID, int64_t nValue);
    bool SetPrivKey(std::string strPrivKey);
    bool CheckSignature(CHubMessage& hub);
    bool Sign(CHubMessage& hub);
    void Relay(CHubMessage& msg);

};

#endif
