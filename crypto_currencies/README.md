# Crypto Currencies
Crypto currency-related notes, for example, on Bitcoin, Ethereum, how it works, etc. - all that jazz.

## General Notes & Concepts
* definition: a digital asset that uses cryptography to secure transactions
* The goal of Bitcoin and other crypto currencies [in general] is to provide a
  decentralized system upon which exchanges can occur without a trusted 
  authority or central server, and protects against the double spending problem.
* the basis of coins are digital signatures
    * signatures offer non-repudiation, authentication, and integrity
* blockchain
    * a chain of records (blocks) secured using cryptographic functions
    * Satoshi Nakamoto conceptualized (2008) the first distributed blockchain
      to serve as a public ledger
    * a blockchain is maintained by a network of communicating nodes 
    * a blockchain is a distributed database; each node has a copy of it
    * the longest blockchain is the "true" blockchain in a network
    * the time it takes for an attacker to undo previous blocks and catch up
      expontentially decreases as more transactions are computed
* mining
    * using cpu processing power, a node/computer will help "keep the blockhain
      consistent, complete, and unalterable by repeatedly verifying and
      collecting newly broadcast transactions into a new group of transactions
      called a block" [wikiArticle](https://en.wikipedia.org/wiki/Bitcoin#Mining)
    * "To be accepted by the rest of the network, a new block must contain a
      so-called proof-of-work."
* proof-of-work system
    * wikipedia:  is an economic measure to deter denial of service attacks and
      other service abuses such as spam on a network by requiring some work from
      the service requester, usually meaning processing time by a computer.
    * challenge-response vs solution-verification protocols
    * ideally, verification at the provider (server) should be quick as possible
* [smart contracts](https://en.wikipedia.org/wiki/Smart_contract)
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

### Terminology & Related Topics
* coins vs altcoins vs tokens
    * https://masterthecrypto.com/differences-between-cryptocurrency-coins-and-tokens/
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
    * ICOs - Initial Coin Offerings are actually token offerings to the public
* Byzantine fault tolerance
* white paper vs yellow paper
    * white paper is higher level, less techy
    * yellow paper is like a research level paper, has all the details, etc.
      typically these do not have authorised value

### Fun Facts
* there will be only 21 million bitcoins supplied
    * approx. 12.5 bitcoins per blocks until 2020, then having every four years
      until no more are distributed, which should be between years 2110-40


## Relevant Papers
* [Bitcoin: A Peer-to-Peer Electronic Cash System](https://bitcoin.org/bitcoin.pdf)
* [Ethereum Yellow Paper](http://yellowpaper.io)

### Links
* [What the f*ck is Ethereum?](http://whatthefuckisethereum.com)
* [CoinMarketCap](https://coinmarketcap.com/coins/)

