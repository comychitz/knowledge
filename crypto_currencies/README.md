# Crypto Currencies
Crypto currency (and related topics) notes.

## General Notes & Concepts
* By definition, a crytographic currency (cyrpto currency) is a digital asset that
    uses cyrptography to secure transactions. There are many examples, the most
    prominent of all being Bitcoin. 
* The heart of many crypto currencies such as Bitcoin is consensus - there must
    be an agreed upon method which the nodes on the network can safely, securely
    and quickly agree upon changes in the state of the system.
* The goal of Bitcoin is to provide a decentralized system upon which exchanges 
    of value can occur without a trusted authority or central server, while 
    protecting against the double spending problemn. 
* Coins are based on digital signatures, which like a person's signature, offers
    non-repudiation, authentication, and integrity. 
* supply is limited(!)
    * there will be only 21 million bitcoins supplied (by desgin)
    * approx. 12.5 bitcoins per blocks until 2020, then halving every four years
      until no more are distributed, which should be between years 2110-40
* The Blockchain 
    * a chain of records (blocks) secured using cryptographic functions to
      serve a public (or private) [distributed ledger](https://en.wikipedia.org/wiki/Distributed_ledger)
    * a blockchain is maintained by a network of communicating nodes (aka a
      peer-to-peer network)
    * a blockchain is a distributed database; each node has a copy of it
    * the longest blockchain is the "true" blockchain in a network
    * "Blockchains are secure by design and are an example of a distributed
      computing system with high Byzantine fault tolerance."
    * the time it takes for an attacker to undo previous blocks and catch up
      expontentially decreases as more transactions are computed
    * Satoshi Nakamoto conceptualized (2008) the first distributed blockchain
      to serve as a [distributed] public ledger (Bitcoin)
* Mining
    * using cpu processing power, a node/computer will help "keep the blockhain
      consistent, complete, and unalterable by repeatedly verifying and
      collecting newly broadcast transactions into a new group of transactions
      called a block" [wikiArticle](https://en.wikipedia.org/wiki/Bitcoin#Mining)
    * "To be accepted by the rest of the network, a new block must contain a
      so-called proof-of-work."
* Proof-of-Work system
    * wikipedia: is an economic measure to deter denial of service attacks and
      other service abuses such as spam on a network by requiring some work from
      the service requester, usually meaning processing time by a computer.
    * challenge-response vs solution-verification protocols
    * ideally, verification at the provider (server) should be quick as possible
    * proof-of-work vs proof-of-stake vs proof-of
* [Smart Contracts](https://en.wikipedia.org/wiki/Smart_contract)
    * first coined in 1996 by Nick Szabo
    * "A smart contract is a set of promises, specified in digital form,
      including protocols within which the parties perform on these promises."
    * A smart contract is "a computerized transaction protocol that executes the
      terms of a contract."
    * A blockchain-based smart contract is visible to all. Meaning all
      bugs/flaws/vulnerabilities can be seen, which is bad if not fixed quickly
    * Decentralized cryptocurrency protocols are smart contracts with
      decentralized security, encryption, and limited trusted parties that fit
      Szabo's definition of a digital agreement with observability,
      verifiability, privity, and enforceability
* Ethereum
    * (read white & yellow papers for full details; links below)
    * so much more to offer than Bitcoin does; Bitcoin is designed and aimed for
        purely exchanges of goods/value, whereas Ethereum is a network upon which
        any type of transaction can occur
    * "one key goal is to facilitate transactions between consenting
      individuals who would otherwise have no means to trust one another"
    * "Early work on smart contracts has been done by Szabo [1997] and Miller
        [1997]. Around the 1990s it became clear that algorithmic enforcement of
        agreements could become a significant force in human cooperation"
    * "The ethereum white paper splits dapps into three types: apps that manage
        money, apps where money is involved (but also requires another piece),
        and apps in the “other” category, which includes voting and governance
        systems."
* Decentralized Applications (dapps)
    * software applications can be thought of as three classes:
      1) centralized 2) decentralied 3) distributed
    * 3 types of dapps:
        * Type I decentralized applications have their own block chain. Bitcoin
        is the most famous example of a type I decentralized application but
        Litecoin and other “alt-coins” are of the same type.
        * Type II decentralized applications use the block chain of a type I
        decentralized application. Type II decentralized applications are
        protocols and have tokens that are necessary for their function. The
        Omni Protocol is an example of a type II decentralized application.
        * Type III decentralized applications use the protocol of a type II
        decentralized application. Type III decentralized applications are
        protocols and have tokens that are necessary for their function. For
        example the SAFE Network that uses the Omni Protocol to issue
        ‘safecoins’ that can be used to acquire distributed file storage is
        an example of a type III decentralized application.
* coins vs altcoins vs tokens
    * altcoins - general term for cryptocurrencies, both those that were
      Bitcoin-Derived blockchains (litecoin, namecoin) or have their own native 
      blockchain (ethereum, ripple, etc.)
    * in general, "coins" is a synonym for "altcoins" 
    * tokens - Tokens are a representation of a particular asset or utility,
      that usually resides on top of another blockchain
        * tokens are built using smart contracts
    * The main difference between altcoins and tokens is in their structure;
      altcoins are separate currencies with their own separate blockchain while
      tokens operate on top of a blockchain that facilitates the creation of
      decentralized applications.
    * The purpose of a token is to allow access to a computer application. For
        example, an individual must own a number of bitcoins in order to be able
        to perform any transaction on the Bitcoin network. Tokens in Dapps do
        not represent any underlying asset, they do not give rights to a
        dividend, and no equity is represented through them. Although the value
        of a Dapp token may increase or decrease over time, tokens are not
        equity securities.
    * ICOs - Initial Coin Offerings are actually token offerings to the public

### Terminology & Related Topics
* white paper vs yellow paper
    * white paper is higher level, less techy
    * yellow paper is like a research level paper, has all the details, etc.
      typically these do not have authorised value
* client software
    * client software != mining software
    * for example, ethereum client software is light-weight interaction with the
        network - meaning interacting with contracts, performing transactions,
        transfering funds, etc. 

## Relevant Papers
* [Bitcoin: A Peer-to-Peer Electronic Cash System](https://bitcoin.org/bitcoin.pdf)
* [Ethereum Yellow Paper](http://yellowpaper.io)
* [Ethereum White Paper](https://github.com/ethereum/wiki/wiki/White-Paper#applications)
* [Ripple - Solution Overview](https://ripple.com/files/ripple_solutions_guide.pdf)
* [The Ripple Protocol Consensus Algorithm](https://ripple.com/files/ripple_consensus_whitepaper.pdf) 
* [The Stellar Consensus Protocol](https://www.stellar.org/papers/stellar-consensus-protocol.pdf)

## Good Reads
* [Hype Cycle for Emerging Technologies - 2017](https://www.forbes.com/sites/louiscolumbus/2017/08/15/gartners-hype-cycle-for-emerging-technologies-2017-adds-5g-and-deep-learning-for-first-time/#c3bf5c504307)
* [Differences between coins & tokens](https://masterthecrypto.com/differences-between-cryptocurrency-coins-and-tokens/)
* [CNBC Explains How To Mine Bitcoins On Your Own](https://www.cnbc.com/2014/01/23/cnbc-explains-how-to-mine-bitcoins-on-your-own.html)
* [What is a Decentralized Application](https://www.coindesk.com/information/what-is-a-decentralized-application-dapp/)
* [The General Theory of Decentralized Applications, Dapps](https://github.com/DavidJohnstonCEO/DecentralizedApplications)

### Links & References
* [CoinMarketCap](https://coinmarketcap.com/coins/)
* [What the f*ck is Ethereum?](http://whatthefuckisethereum.com)

#### Exchanges && Apps
* coinbase.com
* bittrex.com
* binance.com
* blockfolio - Andriod/iOS coin portfolio app

