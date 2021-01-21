// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2019 The Phore Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>
#include <limits>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (      0, uint256("2b1a0f66712aad59ad283662d5b919415a25921ce89511d73019107e380485bf"))
    (   1000, uint256("8defd49579d63545f9e8cdda31f8503e0513328ca3f7428f33a915258c764d15"))
    (  10000, uint256("6af2431daa7456e4620e9493091648eeaac8ddfd53d8cff8101c26806e301d9a"))
    (  90000, uint256("a883d86273f02cb19252a878d1e0bda1e5321140480b08e3df9544d7b3d1ce56"))
    ( 152000, uint256("4dc1a3eb7d17bab4e7f5768e927c9666ba760d6882d3b600519fdd7b83f65610"))
    ( 200000, uint256("9260e1eb2d3851bccd2794e2c61c29af91fcd4b56ba207a4b9a5b1e79b53fb10"))
    ( 340000, uint256("5554c0f33c36f21b79abfda9f92d1b855ed0e67b556361983af6611d75a022b3"))
    ( 390000, uint256("1702d23f4b0f9bbcd98cc34ce90b82dbdb5d4ebf80f135284dfd709b0964f080"))
    ( 420000, uint256("d41c1e9e2621f69aefc51e3748049f366aa6a2415968d6d2035c53410cc40305"))
    ( 440000, uint256("3b60f85e683263783622581fbe02b5b2e59e72ccc8dc5bd6a69650d709596691"))
    ( 445500, uint256("dbccd01f9774835e378b47a307e9d57120fed9409e511e1adc12fe097dc60695"))
    ( 522000, uint256("18a3cb62d0a5a86c13395d970f83cd14a426e56360ecd9d7966530d9afbf1bb0"))
    ( 588223, uint256("5374231f986b41d3745a1ee5d45b7decc65097712cb7d34429f0e1faecb8e5f4"))
    ( 598090, uint256("b753f2a3ba8837ed9efcc9f877f33266b342006c0c8818071b48726e58d2052c"))
    ( 635700, uint256("a90a034b2999c6a3deb69a74d60d01cf5cb78bae8cd8e29ddb4620baf6d67cce"))
    ( 644300, uint256("c1330d826fb13968862bea2a84bd7b19f8a8cc93a83df1b2fe92bbea7050fafa"))
    ( 695367, uint256("da25e97b5308d689197fe0d259ebb38d1087f2b113fd46a7a19a929329cb5640"))
    ( 812197, uint256("b56a80bd01d2b11b5f102e8f1ad307e4d4b4295915032bcb1517e3027d01ae47"))
    ( 850000, uint256("1869b6944c96e0baf683364402b118725c1ffa1eb4f78b539e2a201c4440fd9c"))
    ( 900000, uint256("e2bace64fbce057643e49939987f40d0b9487b4e4ffe2b7852e284463a8e3521"))
    ( 950000, uint256("3150bdf897211c60b895ebbb7884d90c7147a53a8eb413d260d54c4ca3aebc61"))
    (1000000, uint256("a88a1ad20733dda703a73c12916c0b77e6242a71b7f88ad827aee8bd9264c652"))
    (1062034, uint256("3f8c698163c1ba2e641da32fd7e19b394df36136411beb607db3cd6de8a76321"))
    (1119060, uint256("58b0080c0c90a63c2add392f0c2847bed05354f023dd1a9f8d10c8c96ae4bdb5"))
    (1426250, uint256("9bff7d1d1e68ebd1efc239569e7a92d1dc66c36c0ffc8d0afb2767cf2bb582f9"))
    (1474699, uint256("d62b044bc1189e94775942913dec19b9b0121b3f1e06a3c53e9ba8439a81ca04"))
    (1717390, uint256("1e29b76e9ba2003eefa8d4f91872fb742e9e32ac1b390ee53511879ee4f0c6dc"));

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1609699341, // * UNIX timestamp of last checkpoint block
    4422836,     // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    1500        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x2b1a0f66712aad59ad283662d5b919415a25921ce89511d73019107e380485bf"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1504595227,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x2b1a0f66712aad59ad283662d5b919415a25921ce89511d73019107e380485bf"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1504595227,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus;
    bnTrustedModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

libzerocoin::ZerocoinParams* CChainParams::OldZerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus;
    bnTrustedModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

bool CChainParams::HasStakeMinAgeOrDepth(const int contextHeight, const uint32_t contextTime,
                                         const int utxoFromBlockHeight, const uint32_t utxoFromBlockTime) const
{
    // before stake modifier V2, the age required was 3 * 60 * 60 (3 hour) / not required on regtest
    if (!IsStakeModifierV2(contextHeight))
        return (NetworkID() == CBaseChainParams::REGTEST || (utxoFromBlockTime + 10800 <= contextTime));

    // after stake modifier V2, we require the utxo to be nStakeMinDepth deep in the chain
    return (contextHeight - utxoFromBlockHeight >= nStakeMinDepth);
}


class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x82;
        pchMessageStart[1] = 0xb1;
        pchMessageStart[2] = 0xec;
        pchMessageStart[3] = 0xa4;
        vAlertPubKey = ParseHex("047ff78a093ca911fbe3c7cd9b8b81976696d92e6ad3d987b00a4cc4841fe9689ed6902be9c6942ef77492d0531bf68cf2e53dc0ac683359f938a7a52a988ced8c");
        nDefaultPort = 22881;
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetSpacing = 1 * 60;  // Phore: 1 minute
        nStakeMinDepth = 600;
        nFutureTimeDriftPoW = 7200;
        nFutureTimeDriftPoS = 50;
        nMaturity = 10;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 1000000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 200;

        nModifierUpdateBlock = 468744;

        nZerocoinStartHeight = 89993;

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "21 January 2021";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].SetEmpty();
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1611225700;
        genesis.nBits = 0x207fffff;;
        genesis.nNonce = 12345;

        if(genesis.GetHash() != uint256("0x"))
                {
                    printf("Searching for genesis block...\n");
                    uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
                    while(uint256(genesis.GetHash()) > hashTarget)
                    {
                        ++genesis.nNonce;
                        if (genesis.nNonce == 0)
                        {
                            printf("NONCE WRAPPED, incrementing time");
                            std::cout << std::string("NONCE WRAPPED, incrementing time:\n");
                            ++genesis.nTime;
                        }
                        if (genesis.nNonce % 10000 == 0)
                        {
                            printf("Mainnet: nonce %08u: hash = %s \n", genesis.nNonce, genesis.GetHash().ToString().c_str(), genesis.hashMerkleRoot.ToString().c_str());
                        }
                    }
                    printf("block.nTime = %u \n", genesis.nTime);
                    printf("block.nNonce = %u \n", genesis.nNonce);
                    printf("block.GetHash = %s\n", genesis.GetHash().ToString().c_str());
                    printf("block.merklehash = %s\n", genesis.hashMerkleRoot.ToString().c_str());
                }

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x2b1a0f66712aad59ad283662d5b919415a25921ce89511d73019107e380485bf"));
        assert(genesis.hashMerkleRoot == uint256("0x894177137a45952cfed89dd395e7fc85208a53548f34defc7c1a85cb0736b3a3"));

        vSeeds.push_back(CDNSSeedData("0", "209.250.242.145"));
        vSeeds.push_back(CDNSSeedData("1", "45.77.143.65"));
        vSeeds.push_back(CDNSSeedData("2", "45.32.176.208"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 55);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 13);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x03)(0x1C)(0x54)(0x22).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x05)(0x22)(0x32)(0x3A).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        nExtCoinType = 444;

        bech32_hrp = "ph";

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "047ff78a093ca911fbe3c7cd9b8b81976696d92e6ad3d987b00a4cc4841fe9689ed6902be9c6942ef77492d0531bf68cf2e53dc0ac683359f938a7a52a988ced8c";
        strObfuscationPoolDummyAddress = "PCYiHgGJJ6xGHqivmdZrYjRnhaYf6AJ2Mp";

        nBlockStakeModifierlV2 = 1747800; // this will be set at a later date

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";


        nZerocoinLastOldParams = 99999999; // Updated to defer zerocoin v2 for further testing.

        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nBudgetFeeConfirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x44;
        pchMessageStart[1] = 0x86;
        pchMessageStart[2] = 0x75;
        pchMessageStart[3] = 0xbc;
        vAlertPubKey = ParseHex("047ff78a093ca911fbe3c7cd9b8b81976696d92e6ad3d987b00a4cc4841fe9689ed6902be9c6942ef77492d0531bf68cf2e53dc0ac683359f938a7a52a988ced8c");
        nDefaultPort = 22888;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetSpacing = 1 * 10;  // Phore: 1 minute
        nMaturity = 15;
        nStakeMinDepth = 100;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 1; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nLastPOWBlock = 500;
        nZerocoinStartHeight = 600;

        nZerocoinLastOldParams = 500000;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1611225700;
        genesis.nNonce = 12346;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0xfab709a0c107fe7cf6b0d552c514ef3228f9e0f107cd3c9b2fcea96512342cd8"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet phore addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet phore script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet phore BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet phore BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x59)(0x26).convert_to_container<std::vector<unsigned char> >();
        // Testnet phore BIP44 coin type is '1' (All coin's testnet default)
        nExtCoinType = 1;

        bech32_hrp = "tp";

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "047ff78a093ca911fbe3c7cd9b8b81976696d92e6ad3d987b00a4cc4841fe9689ed6902be9c6942ef77492d0531bf68cf2e53dc0ac683359f938a7a52a988ced8c";
        strObfuscationPoolDummyAddress = "PCYiHgGJJ6xGHqivmdZrYjRnhaYf6AJ2Mp";
        nBlockStakeModifierlV2 = 1500; // this will be set at a later date
        nBudgetFeeConfirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                     // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa2;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetSpacing = 1 * 60;        // Phore: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1611225700;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;
        nMaturity = 0;
        nStakeMinDepth = 0;
        nLastPOWBlock = 999999999; // PoS complicates Regtest because of timing issues
        nZerocoinLastOldParams = 499;
        nZerocoinStartHeight = 100;

        nBlockStakeModifierlV2 = std::numeric_limits<int>::max(); // max integer value (never switch on regtest)

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 22888;
        assert(hashGenesisBlock == uint256("0x2b1a0f66712aad59ad283662d5b919415a25921ce89511d73019107e380485bf"));

        bech32_hrp = "phrt";

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
        nRequiredAccumulation = 1;

        // {
        //     "PrivateKey": "923EhWh2bJHynX6d4Tqt2Q75bhTDCT1b4kff3qzDKDZHZ6pkQs7",
        //     "PublicKey": "04866dc02c998b7e1ab16fe14e0d86554595da90c36acb706a4d763b58ed0edb1f82c87e3ced065c5b299b26e12496956b9e5f9f19aa008b5c46229b15477c875a"
        // }
        strSporkKey = "047ff78a093ca911fbe3c7cd9b8b81976696d92e6ad3d987b00a4cc4841fe9689ed6902be9c6942ef77492d0531bf68cf2e53dc0ac683359f938a7a52a988ced8c";
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 22884;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        nExtCoinType = 1;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
