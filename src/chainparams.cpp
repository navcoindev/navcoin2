// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x80;
        pchMessageStart[1] = 0x50;
        pchMessageStart[2] = 0x34;
        pchMessageStart[3] = 0x20;
        vAlertPubKey = ParseHex("0486bce1bac0d543f104cbff2bd23680056a3b9ea05e1137d2ff90eeb5e08472eb500322593a2cb06fbf8297d7beb6cd30cb90f98153b5b7cce1493749e41e0284");
        nDefaultPort = 44440;
        nRPCPort = 44444;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
        //CBlock(hash=000001faef25dec4fbcf906e6242621df2c183bf232f263d0ba5b101911e4563, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=12630d16a97f24b287c8c2594dda5fb98c9e6c70fc61d44191931ea2aa08dc90, nTime=1393221600, nBits=1e0fffff, nNonce=164482, vtx=1, vchBlockSig=)
        //  Coinbase(hash=12630d16a9, nTime=1393221600, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //    CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a24323020466562203230313420426974636f696e2041544d7320636f6d6520746f20555341)
        //    CTxOut(empty)
        //  vMerkleTree: 12630d16a9
        const char* pszTimestamp = "Game is afoot!";
        CTransaction txNew;
        txNew.nTime = 1460561040;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].SetEmpty();
		txNew.strDZeel = "NavCoin genesis block";
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1460561040;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact(); 
        genesis.nNonce   = 6945;

		hashGenesisBlock = genesis.GetHash();
		//// debug print
/*        while (hashGenesisBlock > bnProofOfWorkLimit.getuint256()){
        if (++genesis.nNonce==0) break;
        hashGenesisBlock = genesis.GetHash();
        }
        printf("%s\n MAIN ", hashGenesisBlock.ToString().c_str());
        printf("%s\n MAIN ", genesis.hashMerkleRoot.ToString().c_str());
        printf("%x\n MAIN ", bnProofOfWorkLimit.GetCompact());
        printf("%d\n MAIN ", genesis.nNonce);
*/
        assert(hashGenesisBlock == uint256("0x00006a4e3e18c71c6d48ad6c261e2254fa764cf29607a4357c99b712dfbb8e6a"));
        assert(genesis.hashMerkleRoot == uint256("0xc507eec6ccabfd5432d764afceafba42d2d946594b8a60570cb2358a7392c61a"));

		vSeeds.push_back(CDNSSeedData("supernode.navcoin.org", "supernode.navcoin.org"));
        
        base58Prefixes[PUBKEY_ADDRESS] = list_of(53);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(85);
        base58Prefixes[SECRET_KEY] =     list_of(150);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);
        base58Prefixes[EXT_COIN_TYPE]  = list_of(0x80000082);             // NavCoin BIP44 coin type is '82' Index "130"

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 20000;
        nPOSStartBlock = 2;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x80;
        pchMessageStart[1] = 0x50;
        pchMessageStart[2] = 0x34;
        pchMessageStart[3] = 0x20;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("0471dc165db490094d35cde15b1f5d755fa6ad6f2b5ed0f340e3f17f57389c3c2af113a8cbcc885bde73305a553b5640c83021128008ddf882e856336269080496");
        nDefaultPort = 33440;
        nRPCPort = 33444;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = 520159231; 
        genesis.nNonce = 6945;

/*
        while (hashGenesisBlock > bnProofOfWorkLimit.getuint256()){
            if (++genesis.nNonce==0) break;
            hashGenesisBlock = genesis.GetHash();
        }
        printf("%s\n TESTNET ", hashGenesisBlock.ToString().c_str());
        printf("%s\n TESTNET ", genesis.hashMerkleRoot.ToString().c_str());
        printf("%x\n TESTNET ", bnProofOfWorkLimit.GetCompact());
        printf("%d\n TESTNET ", genesis.nNonce);       
*/
	    assert(hashGenesisBlock == uint256("0x00006a4e3e18c71c6d48ad6c261e2254fa764cf29607a4357c99b712dfbb8e6a"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = list_of(53);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(85);
        base58Prefixes[SECRET_KEY]     = list_of(150);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);
        base58Prefixes[EXT_COIN_TYPE]  = list_of(0x80000082);             // NavCoin BIP44 coin type is '82' Index "130"

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);
    
    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
