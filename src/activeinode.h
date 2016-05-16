// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef ACTIVEINODE_H
#define ACTIVEINODE_H

#include "uint256.h"
#include "sync.h"
#include "net.h"
#include "key.h"
//#include "primitives/transaction.h"
#include "main.h"
#include "init.h"
#include "wallet.h"
#include "anonsend.h"

// Responsible for activating the inode and pinging the network
class CActiveInode
{
public:
	// Initialized by init.cpp
	// Keys for the main inode
	CPubKey pubKeyInode;

	// Initialized while registering inode
	CTxIn vin;
    CService service;

    int status;
    std::string notCapableReason;

    CActiveInode()
    {        
        status = INODE_NOT_PROCESSED;
    }

    void ManageStatus(); // manage status of main inode

    bool Dseep(std::string& errorMessage); // ping for main inode
    bool Dseep(CTxIn vin, CService service, CKey key, CPubKey pubKey, std::string &retErrorMessage, bool stop); // ping for any inode

    bool StopINode(std::string& errorMessage); // stop main inode
    bool StopINode(std::string strService, std::string strKeyInode, std::string& errorMessage); // stop remote inode
    bool StopINode(CTxIn vin, CService service, CKey key, CPubKey pubKey, std::string& errorMessage); // stop any inode

    bool Register(std::string strService, std::string strKey, std::string txHash, std::string strOutputIndex, std::string& errorMessage); // register remote inode
    bool Register(CTxIn vin, CService service, CKey key, CPubKey pubKey, CKey keyInode, CPubKey pubKeyInode, std::string &retErrorMessage); // register any inode
    bool RegisterByPubKey(std::string strService, std::string strKeyInode, std::string collateralAddress, std::string& errorMessage); // register for a specific collateral address

    // get 100000NAV input that can be used for the inode
    bool GetINodeVin(CTxIn& vin, CPubKey& pubkey, CKey& secretKey);
    bool GetINodeVin(CTxIn& vin, CPubKey& pubkey, CKey& secretKey, std::string strTxHash, std::string strOutputIndex);
    bool GetINodeVinForPubKey(std::string collateralAddress, CTxIn& vin, CPubKey& pubkey, CKey& secretKey);
    bool GetINodeVinForPubKey(std::string collateralAddress, CTxIn& vin, CPubKey& pubkey, CKey& secretKey, std::string strTxHash, std::string strOutputIndex);
    vector<COutput> SelectCoinsInode();
    vector<COutput> SelectCoinsInodeForPubKey(std::string collateralAddress);
    bool GetVinFromOutput(COutput out, CTxIn& vin, CPubKey& pubkey, CKey& secretKey);

    // enable hot wallet mode (run a inode with no funds)
    bool EnableHotColdINode(CTxIn& vin, CService& addr);
};

#endif
