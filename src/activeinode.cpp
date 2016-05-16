// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "protocol.h"
#include "activeinode.h"
#include <boost/lexical_cast.hpp>
#include "clientversion.h"

//
// Bootup the inode, look for a 500 NAV input and register on the network
//
void CActiveInode::ManageStatus()
{
    std::string errorMessage;

    if(!fINode) return;

    if (fDebug) LogPrintf("CActiveInode::ManageStatus() - Begin\n");

    //need correct adjusted time to send ping
    bool fIsInitialDownload = IsInitialBlockDownload();
    if(fIsInitialDownload) {
        status = INODE_SYNC_IN_PROCESS;
        LogPrintf("CActiveInode::ManageStatus() - Sync in progress. Must wait until sync is complete to start inode.\n");
        return;
    }

    if(status == INODE_INPUT_TOO_NEW || status == INODE_NOT_CAPABLE || status == INODE_SYNC_IN_PROCESS){
        status = INODE_NOT_PROCESSED;
    }

    if(status == INODE_NOT_PROCESSED) {
        if(strINodeAddr.empty()) {
            if(!GetLocal(service)) {
                notCapableReason = "Can't detect external address. Please use the inodeaddr configuration option.";
                status = INODE_NOT_CAPABLE;
                LogPrintf("CActiveInode::ManageStatus() - not capable: %s\n", notCapableReason.c_str());
                return;
            }
        } else {
        	service = CService(strINodeAddr);
        }

        LogPrintf("CActiveInode::ManageStatus() - Checking inbound connection to '%s'\n", service.ToString().c_str());

                  
            if(!ConnectNode((CAddress)service, service.ToString().c_str())){
                notCapableReason = "Could not connect to " + service.ToString();
                status = INODE_NOT_CAPABLE;
                LogPrintf("CActiveInode::ManageStatus() - not capable: %s\n", notCapableReason.c_str());
                return;
            }
        

        if(pwalletMain->IsLocked()){
            notCapableReason = "Wallet is locked.";
            status = INODE_NOT_CAPABLE;
            LogPrintf("CActiveInode::ManageStatus() - not capable: %s\n", notCapableReason.c_str());
            return;
        }

        // Set defaults
        status = INODE_NOT_CAPABLE;
        notCapableReason = "Unknown. Check debug.log for more information.\n";

        // Choose coins to use
        CPubKey pubKeyCollateralAddress;
        CKey keyCollateralAddress;

        if(GetINodeVin(vin, pubKeyCollateralAddress, keyCollateralAddress)) {

            if(GetInputAge(vin) < INODE_MIN_CONFIRMATIONS){
                LogPrintf("CActiveInode::ManageStatus() - Input must have least %d confirmations - %d confirmations\n", INODE_MIN_CONFIRMATIONS, GetInputAge(vin));
                status = INODE_INPUT_TOO_NEW;
                return;
            }

            LogPrintf("CActiveInode::ManageStatus() - Is capable inode!\n");

            status = INODE_IS_CAPABLE;
            notCapableReason = "";

            pwalletMain->LockCoin(vin.prevout);

            // send to all nodes
            CPubKey pubKeyInode;
            CKey keyInode;

            if(!anonSendSigner.SetKey(strINodePrivKey, errorMessage, keyInode, pubKeyInode))
            {
            	LogPrintf("Register::ManageStatus() - Error upon calling SetKey: %s\n", errorMessage.c_str());
            	return;
            }

            if(!Register(vin, service, keyCollateralAddress, pubKeyCollateralAddress, keyInode, pubKeyInode, errorMessage)) {
            	LogPrintf("CActiveInode::ManageStatus() - Error on Register: %s\n", errorMessage.c_str());
            }

            return;
        } else {
        	LogPrintf("CActiveInode::ManageStatus() - Could not find suitable coins!\n");
        }
    }

    //send to all peers
    if(!Dseep(errorMessage)) {
    	LogPrintf("CActiveInode::ManageStatus() - Error on Ping: %s", errorMessage.c_str());
    }
}

// Send stop dseep to network for remote inode
bool CActiveInode::StopINode(std::string strService, std::string strKeyInode, std::string& errorMessage) {
	CTxIn vin;
    CKey keyInode;
    CPubKey pubKeyInode;

    if(!anonSendSigner.SetKey(strKeyInode, errorMessage, keyInode, pubKeyInode)) {
    	LogPrintf("CActiveInode::StopINode() - Error: %s\n", errorMessage.c_str());
		return false;
	}

	return StopINode(vin, CService(strService), keyInode, pubKeyInode, errorMessage);
}

// Send stop dseep to network for main inode
bool CActiveInode::StopINode(std::string& errorMessage) {
	if(status != INODE_IS_CAPABLE && status != INODE_REMOTELY_ENABLED) {
		errorMessage = "inode is not in a running status";
    	LogPrintf("CActiveInode::StopINode() - Error: %s\n", errorMessage.c_str());
		return false;
	}

	status = INODE_STOPPED;

    CPubKey pubKeyInode;
    CKey keyInode;

    if(!anonSendSigner.SetKey(strINodePrivKey, errorMessage, keyInode, pubKeyInode))
    {
    	LogPrintf("Register::ManageStatus() - Error upon calling SetKey: %s\n", errorMessage.c_str());
    	return false;
    }

	return StopINode(vin, service, keyInode, pubKeyInode, errorMessage);
}

// Send stop dseep to network for any inode
bool CActiveInode::StopINode(CTxIn vin, CService service, CKey keyInode, CPubKey pubKeyInode, std::string& errorMessage) {
   	pwalletMain->UnlockCoin(vin.prevout);
	return Dseep(vin, service, keyInode, pubKeyInode, errorMessage, true);
}

bool CActiveInode::Dseep(std::string& errorMessage) {
	if(status != INODE_IS_CAPABLE && status != INODE_REMOTELY_ENABLED) {
		errorMessage = "inode is not in a running status";
    	LogPrintf("CActiveInode::Dseep() - Error: %s\n", errorMessage.c_str());
		return false;
	}

    CPubKey pubKeyInode;
    CKey keyInode;

    if(!anonSendSigner.SetKey(strINodePrivKey, errorMessage, keyInode, pubKeyInode))
    {
    	LogPrintf("Register::ManageStatus() - Error upon calling SetKey: %s\n", errorMessage.c_str());
    	return false;
    }

	return Dseep(vin, service, keyInode, pubKeyInode, errorMessage, false);
}

bool CActiveInode::Dseep(CTxIn vin, CService service, CKey keyInode, CPubKey pubKeyInode, std::string &retErrorMessage, bool stop) {
    std::string errorMessage;
    std::vector<unsigned char> vchINodeSignature;
    std::string strINodeSignMessage;
    int64_t iNodeSignatureTime = GetAdjustedTime();

    std::string strMessage = service.ToString() + boost::lexical_cast<std::string>(iNodeSignatureTime) + boost::lexical_cast<std::string>(stop);

    if(!anonSendSigner.SignMessage(strMessage, errorMessage, vchINodeSignature, keyInode)) {
    	retErrorMessage = "sign message failed: " + errorMessage;
    	LogPrintf("CActiveInode::Dseep() - Error: %s\n", retErrorMessage.c_str());
        return false;
    }

    if(!anonSendSigner.VerifyMessage(pubKeyInode, vchINodeSignature, strMessage, errorMessage)) {
    	retErrorMessage = "Verify message failed: " + errorMessage;
    	LogPrintf("CActiveInode::Dseep() - Error: %s\n", retErrorMessage.c_str());
        return false;
    }

    // Update Last Seen timestamp in inode list
    bool found = false;
    BOOST_FOREACH(CINode& mn, vecInodes) {
        //LogPrintf(" -- %s\n", mn.vin.ToString().c_str());
        if(mn.vin == vin) {
            found = true;
            mn.UpdateLastSeen();
        }
    }

    if(!found){
    	// Seems like we are trying to send a ping while the inode is not registered in the network
    	retErrorMessage = "Anonsend Inode List doesn't include our inode, Shutting down inode pinging service! " + vin.ToString();
    	LogPrintf("CActiveInode::Dseep() - Error: %s\n", retErrorMessage.c_str());
        status = INODE_NOT_CAPABLE;
        notCapableReason = retErrorMessage;
        return false;
    }

    //send to all peers
    LogPrintf("CActiveInode::Dseep() - SendAnonSendElectionEntryPing vin = %s\n", vin.ToString().c_str());
    SendAnonSendElectionEntryPing(vin, vchINodeSignature, iNodeSignatureTime, stop);

    return true;
}

bool CActiveInode::RegisterByPubKey(std::string strService, std::string strKeyInode, std::string collateralAddress, std::string& errorMessage) {
	CTxIn vin;
    CPubKey pubKeyCollateralAddress;
    CKey keyCollateralAddress;
    CPubKey pubKeyInode;
    CKey keyInode;

    if(!anonSendSigner.SetKey(strKeyInode, errorMessage, keyInode, pubKeyInode))
    {
    	LogPrintf("CActiveInode::RegisterByPubKey() - Error upon calling SetKey: %s\n", errorMessage.c_str());
    	return false;
    }

    if(!GetINodeVinForPubKey(collateralAddress, vin, pubKeyCollateralAddress, keyCollateralAddress)) {
		errorMessage = "could not allocate vin for collateralAddress";
    	LogPrintf("Register::Register() - Error: %s\n", errorMessage.c_str());
		return false;
	}
	return Register(vin, CService(strService), keyCollateralAddress, pubKeyCollateralAddress, keyInode, pubKeyInode, errorMessage);
}

bool CActiveInode::Register(std::string strService, std::string strKeyInode, std::string txHash, std::string strOutputIndex, std::string& errorMessage) {
	CTxIn vin;
    CPubKey pubKeyCollateralAddress;
    CKey keyCollateralAddress;
    CPubKey pubKeyInode;
    CKey keyInode;

    if(!anonSendSigner.SetKey(strKeyInode, errorMessage, keyInode, pubKeyInode))
    {
    	LogPrintf("CActiveInode::Register() - Error upon calling SetKey: %s\n", errorMessage.c_str());
    	return false;
    }

    if(!GetINodeVin(vin, pubKeyCollateralAddress, keyCollateralAddress, txHash, strOutputIndex)) {
		errorMessage = "could not allocate vin";
    	LogPrintf("Register::Register() - Error: %s\n", errorMessage.c_str());
		return false;
	}
	return Register(vin, CService(strService), keyCollateralAddress, pubKeyCollateralAddress, keyInode, pubKeyInode, errorMessage);
}

bool CActiveInode::Register(CTxIn vin, CService service, CKey keyCollateralAddress, CPubKey pubKeyCollateralAddress, CKey keyInode, CPubKey pubKeyInode, std::string &retErrorMessage) {
    std::string errorMessage;
    std::vector<unsigned char> vchINodeSignature;
    std::string strINodeSignMessage;
    int64_t iNodeSignatureTime = GetAdjustedTime();

    std::string vchPubKey(pubKeyCollateralAddress.begin(), pubKeyCollateralAddress.end());
    std::string vchPubKey2(pubKeyInode.begin(), pubKeyInode.end());

    std::string strMessage = service.ToString() + boost::lexical_cast<std::string>(iNodeSignatureTime) + vchPubKey + vchPubKey2 + boost::lexical_cast<std::string>(PROTOCOL_VERSION);

    if(!anonSendSigner.SignMessage(strMessage, errorMessage, vchINodeSignature, keyCollateralAddress)) {
		retErrorMessage = "sign message failed: " + errorMessage;
		LogPrintf("CActiveInode::Register() - Error: %s\n", retErrorMessage.c_str());
		return false;
    }

    if(!anonSendSigner.VerifyMessage(pubKeyCollateralAddress, vchINodeSignature, strMessage, errorMessage)) {
		retErrorMessage = "Verify message failed: " + errorMessage;
		LogPrintf("CActiveInode::Register() - Error: %s\n", retErrorMessage.c_str());
		return false;
	}

    bool found = false;
    LOCK(cs_inodes);
    BOOST_FOREACH(CINode& mn, vecInodes)
        if(mn.vin == vin)
            found = true;

    if(!found) {
        LogPrintf("CActiveInode::Register() - Adding to inode list service: %s - vin: %s\n", service.ToString().c_str(), vin.ToString().c_str());
        CINode mn(service, vin, pubKeyCollateralAddress, vchINodeSignature, iNodeSignatureTime, pubKeyInode, PROTOCOL_VERSION);
        mn.UpdateLastSeen(iNodeSignatureTime);
        vecInodes.push_back(mn);
    }

    //send to all peers
    LogPrintf("CActiveInode::Register() - SendAnonSendElectionEntry vin = %s\n", vin.ToString().c_str());
    SendAnonSendElectionEntry(vin, service, vchINodeSignature, iNodeSignatureTime, pubKeyCollateralAddress, pubKeyInode, -1, -1, iNodeSignatureTime, PROTOCOL_VERSION);

    return true;
}

bool CActiveInode::GetINodeVin(CTxIn& vin, CPubKey& pubkey, CKey& secretKey) {
	return GetINodeVin(vin, pubkey, secretKey, "", "");
}

bool CActiveInode::GetINodeVin(CTxIn& vin, CPubKey& pubkey, CKey& secretKey, std::string strTxHash, std::string strOutputIndex) {
    CScript pubScript;

    // Find possible candidates
    vector<COutput> possibleCoins = SelectCoinsInode();
    COutput *selectedOutput;

    // Find the vin
	if(!strTxHash.empty()) {
		// Let's find it
		uint256 txHash(strTxHash);
        int outputIndex = boost::lexical_cast<int>(strOutputIndex);
		bool found = false;
		BOOST_FOREACH(COutput& out, possibleCoins) {
			if(out.tx->GetHash() == txHash && out.i == outputIndex)
			{
				selectedOutput = &out;
				found = true;
				break;
			}
		}
		if(!found) {
			LogPrintf("CActiveInode::GetINodeVin - Could not locate valid vin\n");
			return false;
		}
	} else {
		// No output specified,  Select the first one
		if(possibleCoins.size() > 0) {
			selectedOutput = &possibleCoins[0];
		} else {
			LogPrintf("CActiveInode::GetINodeVin - Could not locate specified vin from possible list\n");
			return false;
		}
    }

	// At this point we have a selected output, retrieve the associated info
	return GetVinFromOutput(*selectedOutput, vin, pubkey, secretKey);
}

bool CActiveInode::GetINodeVinForPubKey(std::string collateralAddress, CTxIn& vin, CPubKey& pubkey, CKey& secretKey) {
	return GetINodeVinForPubKey(collateralAddress, vin, pubkey, secretKey, "", "");
}

bool CActiveInode::GetINodeVinForPubKey(std::string collateralAddress, CTxIn& vin, CPubKey& pubkey, CKey& secretKey, std::string strTxHash, std::string strOutputIndex) {
    CScript pubScript;

    // Find possible candidates
    vector<COutput> possibleCoins = SelectCoinsInodeForPubKey(collateralAddress);
    COutput *selectedOutput;

    // Find the vin
	if(!strTxHash.empty()) {
		// Let's find it
		uint256 txHash(strTxHash);
        int outputIndex = boost::lexical_cast<int>(strOutputIndex);
		bool found = false;
		BOOST_FOREACH(COutput& out, possibleCoins) {
			if(out.tx->GetHash() == txHash && out.i == outputIndex)
			{
				selectedOutput = &out;
				found = true;
				break;
			}
		}
		if(!found) {
			LogPrintf("CActiveInode::GetINodeVinForPubKey - Could not locate valid vin\n");
			return false;
		}
	} else {
		// No output specified,  Select the first one
		if(possibleCoins.size() > 0) {
			selectedOutput = &possibleCoins[0];
		} else {
			LogPrintf("CActiveInode::GetINodeVinForPubKey - Could not locate specified vin from possible list\n");
			return false;
		}
    }

	// At this point we have a selected output, retrieve the associated info
	return GetVinFromOutput(*selectedOutput, vin, pubkey, secretKey);
}


// Extract inode vin information from output
bool CActiveInode::GetVinFromOutput(COutput out, CTxIn& vin, CPubKey& pubkey, CKey& secretKey) {

    CScript pubScript;

	vin = CTxIn(out.tx->GetHash(),out.i);
    pubScript = out.tx->vout[out.i].scriptPubKey; // the inputs PubKey

	CTxDestination address1;
    ExtractDestination(pubScript, address1);
    CBitcoinAddress address2(address1);

    CKeyID keyID;
    if (!address2.GetKeyID(keyID)) {
        LogPrintf("CActiveInode::GetINodeVin - Address does not refer to a key\n");
        return false;
    }

    if (!pwalletMain->GetKey(keyID, secretKey)) {
        LogPrintf ("CActiveInode::GetINodeVin - Private key for address is not known\n");
        return false;
    }

    pubkey = secretKey.GetPubKey();
    return true;
}

// get all possible outputs for running inode
vector<COutput> CActiveInode::SelectCoinsInode()
{
    vector<COutput> vCoins;
    vector<COutput> filteredCoins;

    // Retrieve all possible outputs
    pwalletMain->AvailableCoinsIN(vCoins);

    // Filter
    BOOST_FOREACH(const COutput& out, vCoins)
    {
        if(out.tx->vout[out.i].nValue == 100000*COIN) { //exactly
        	filteredCoins.push_back(out);
        }
    }
    return filteredCoins;
}

// get all possible outputs for running inode for a specific pubkey
vector<COutput> CActiveInode::SelectCoinsInodeForPubKey(std::string collateralAddress)
{
    CBitcoinAddress address(collateralAddress);
    CScript scriptPubKey;
    scriptPubKey.SetDestination(address.Get());
    vector<COutput> vCoins;
    vector<COutput> filteredCoins;

    // Retrieve all possible outputs
    pwalletMain->AvailableCoins(vCoins);

    // Filter
    BOOST_FOREACH(const COutput& out, vCoins)
    {
        if(out.tx->vout[out.i].scriptPubKey == scriptPubKey && out.tx->vout[out.i].nValue == 100000*COIN) { //exactly
        	filteredCoins.push_back(out);
        }
    }
    return filteredCoins;
}

// when starting a inode, this can enable to run as a hot wallet with no funds
bool CActiveInode::EnableHotColdINode(CTxIn& newVin, CService& newService)
{
    if(!fINode) return false;

    status = INODE_REMOTELY_ENABLED;

    //The values below are needed for signing dseep messages going forward
    this->vin = newVin;
    this->service = newService;

    LogPrintf("CActiveInode::EnableHotColdINode() - Enabled! You may shut down the cold daemon.\n");

    return true;
}
