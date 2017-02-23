#network security
some notes on network security

## general notes
* active vs passive attacks: 
   * active: attempt to alter a system (ex. DoS, spoofing, man-in-the-middle attack, ARP poisoning, ping flood, ping of death, smurf attach)
   * passive: attempt to learn about a system (ex. nmap, wiretapping)
* security concepts:
  * confidentiality - only the sender and the intended receiver should see message
  * authentication - sender and reciever want to confirm their identities
  * message integrity - sender/receiver wants to ensure that messages are not alrtered without detection
  * access & availability - services must be access and available to users
  

### cryptography
* steganography -  the practice of concealing a file/message/image/video within another file/message/image/video.
* ECB: electronic code-book - if input block is repeated, it will produce the same cipher text
* CBC: cipher block chaining, XOR i-th input block, m(i), with previous block of cipher text, c(i-1), therefore encryption is dependent on each previous block.
* symmetric key vs public-key (asymmetric)
    * symmetric key: same keys shared by both parties
      * DES
       * 56 bit symmetric key, 64 bit plaintext input
       * can make DES more secure by using three keys sequential on each block (3DES) or use cipher block chaining (which hides patterns, prevents block rearrangement/deletion attacks)
       * DES operation
         * initial permutation
         * 16 identical rounds of canteen application using different 48 bits of key
         * final permutation
      * AES
       * processes data in 128 but blocks
       * supports 128, 192, 256 bit keys
       * brute force decryption on DES takes 1 sec vs 149 trillion years for AES
    * public-key (asymmetric): sender and receiver do not per-share secret key
      * public key is known to all
      * private decryption known only to receiver
      * given a public key, it should be impossibnle to compule the private key
      * RSA
        * Choosing Keys:
          1. Choose two large prime numbers p, q
          2. Compute n = pq, z = (p -1)(q-1)
          3. Choose e (e < n) that has no common factors with z (e & z relatively prime)
          4. Choose d such that ed-1 is exactly divisible by z (ed mod z = 1)
          5. Public key is (n,e) and private key is (n,d)
        * Encryption, decryption
          1. Given (n,e) and (n,d) as computed above
          2. To encrypt “message” m compute c = me mod n
          3. To decrypt cipher text c compute , m = cd mod n
            m = (me mod n)d mod n
        * Important property of RSA:
          * use public key to encrypt first, then public key to encrypt that will be the same if you did it in reverse order. 
* Data Integrity
  * Message Authentication Code (MAC)
    * When Alice sends to Bob a message she will use the message (m) and secret key (s) and hash it and append it to the message before sending (i.e. will send m + H(m+s) ) and then bob does the same with the secret key and the message and compares the result of H(m+s) to the one that Alice sent with the message. MD5, SHA-1, and SHA-2 are hash functions used. but SHA-2 is the only secure one.
  * Digital Signatures
* Authentication
* Secure Email: PGP
* SSL (Sceurity Sockets Layer)
* IPSec
    * an end-to-end security scheme operating in the Internet Layer of the IP Suite. IPsec uses several protocols to perform different functions. 
        * AH - Authentication Header Protocol is uses to provide connectionless integrity and data origin authentication and provides protection against replay attacks, but no confidentiality.
        * ESP - Encapsulating Security Payloads - provides confidentiality, data-origin authentication, connectionless integrity, an anti-replay service, and limited traffic flow confidentiality.

## wireless security
* First WEP came out (Wired Equivalent Privacy), which was a failure due to the architecture
  * authentication scheme same as protocol ap4.0
    * host requests authentication from access point
    * access point send 128 bit nonce
    * host encrypts nonce using shared symmetric key
    * access point decrypts nonce, authenticates host
  * no key distribution mechanism
  * WEP data encryption
    * host/AP share 40 bit symmetric key (semi-permanent)
    * host appends 24-bit initialization vector (IV) to create 64-bit key
    * 64 bit key used to generate stream of keys
    * stream of keys used to encrypt with byte in frame
    * IV and encrypted bytes, c sub i, sent in frame
  * Security Hole:
    * 24bit IV, one IV per frame, IVs will be reused eventually
    * IV transmitted in plaintext, can detect IV reuse
    * potential attack shown to the right
* 802.11i was then made
  * numerous strong forms of encryption
  * provides key distribution
  * uses authentication server separate from access point
* EAP extensible authentication protocol
  * end to end client (mobile) to authentication server protocol
  * sent over separate “links”
    * mobile to AP (EAP over LAN)
    * AP to authentication server (RADIUS over UDP)
* Firewalls and IDSs
  * Firewalls isolate organization’s internal net from larger Internet, allowing some packets to pass, blocking others.
  * Why?
    * prevent DOS attacks (SYN flooding)
    * prevent illegal modification/access of internal data
    * allow only authorized access to inside network
    * three types of firewalls
      * stateless packet filtering
      * stateful packet filtering
      * application gateways
    * Stateless packet filtering
      * filter pack-by-packet based on: source IP address, destination IP address, TCP/UDP source and destination port numbers, ICMP message type, TCP SYN and ACK bits
    * Stateful packet filtering
      * Uses Access Control Lists (ACL) which is a table of rules, applied to top to bottom to incoming packets. consists of action, condition pairs
      * tracks status of every TCP connection
        * track connection setup (SYN)  and teardown (FIN) and can determine whereto incoming, outgoing packets “make sense”
        * timeout inactive connections at firewall: no long admit packets
        * can be augmented to check connection state table before admitting packets
* Application Gateways
  * filters packets on application data as well as on IP/TCP/UDP fields
* Limitations of firewalls and gateways
  * IP spoofing
  * if multiple applications need special treatment, each has its own gateway
  * client software must known how to contact gateway
  * filters often us all or nothing policy for UDP
  * compromise/tradeoff: degree of communication with outside world vs level of security
  * many highly protected sites still suffer from attacks
* IDS - Intrusion Detection Systems
  * deep packet inspection: look at packet contents (check character strings in packet against database of known virus, attack strings, etc.)
  * examine correlation among multiple packets
    * port scanning, network mapping, DoS attack
  * can be set up using multiple IDSs to do different types of checking at different places

### User Authentication
* Password Based authentication
  * Unix Password system
    * Uses DES encryption as a hash function
    * Encrypts NULL string (repeatedly) using passwords as the key. Truncates passwords to 8 characters, artificial slowdown: runs DES 25 times
    * Problem: passwords are not truly random
  * Dictionary Attack: password file /etc/passwd is world readable file where hashes of passwords are stored.
  * Salting - takes a part of the hashed password from the file and (typically) appends it to the password and then hashes that again. salt is chosen when password is created.
    * Advantages: without slat, attack can pre-compute hashes of all dictionary words once for all password entries
    * Attack must compute hashes for all combinations of dictionary words along with the salt. 12 bit random salt will cause 4096 possible different values for the attacker to try for each pwd
  * Shadow passwords: stores hashed passwords in /etc/shadow file which is only readable by root. also adds expression dates for passwords
  * password security risks: keystroke loggers (hw & sw), shoulder surfing, same password at multiple sites, broken implementations, social engineering
  * How people use passwords: same password multiple places, easy to remember, write on paper
  * Memorability vs Security
    * one bank tried to put a word in correspondence with your pin and then fill in the rest of the grid with random letters. only you know the word. 
  * Heuristics for guessing attacks
    * dictionary with words spelled backwards, first and last names, streets, cities, same with upper=case initials, all valid license plate numbers in your state, room numbers, telephone numbers, foreign languages, letter substitutions, etc.
  * Strengthening passwords: add biometrics, graphical passwords
  * Graphical passwords
    * Pass faces
    * Images that make a story or something
  * Biometrics
    * Problems
      * Identification vs authentication
        * Identification = associating an identity with an even or a piece of data
        * authentication - verifying a claimed identity
      * Potentially expensive
      * Fraud rate vs insult rate
        * Fraud rate = system accepts a forgery (false accept)
        * insult rate = system rejects valid user (false reject)
        * even 1% fraud rate is not good enough!
      * Types: Face recognition, fingerprints, iris scans, hand geometry, voice, ear shape, wrist vein pattern, face temperature, etc.
      * Forged computer handwriting
      * Play-Doh fingers
  * Challenge Response Authentication
    * Lamport’s Hash (S/Key OTP system)
      * Main idea: hash chain
        * moving up the chain (computing the next hash) is easy, moving down the chain (inverting the hash) is hard
        * n should be large (can only use it for n authentications)
        * for verification only need the root (upmost link) of the chain
  * Secure ID: generate a random key by using a custom function where the input is a 64 bit key, then with a 24 bit counter will output a 6 digit value. 
  * Honey Passwords
    * computer system and honey checker
    * benefits of honey checker design
      * computer system does nothing but transmit sweet word index
      * get the benefits of distributed security. compromise of either components isn’t fatal. no single point of compromise, compromise of both brings us back to hashed case
      * Honeychecker can be a minimalist thing, pretty much input only with a rare occurrence of output 
      * honeychecker can be offline. it can sit inside a security operations center. 
      * if honey checker goes down can still authenticate 
    * honey word generation
      * Chaffing with a password model
      * chaffing by tweaking
      * with  a flat honor distribution, adversary hits a honeyword at 95%
      * generation can be hybridized
    * honeywords are a kind of poor man’s distributed security system
    * strikes an attractive balance between ease of deployment and security
      * little modification to computer system,
      * honeychecker is minimalist
      * conceptually simple

## web auth
* web authentication using HTTP
  * Stateless request/response protocol - each requisition is independent on previous requests, statelessness has a significant impact on design and implementation of applications
* Authenticators
  * after a user logs into a website they are given a special URL containing the authenticator, which are global sequence numbers. They can be easily guessed if using weak authenticator generators, need to be random.
  * Encoding states in URL is a bad idea. urls frequently change, are vulnerable to eavesdropping and there is no guarantee that a URL is private
* Cookies - file created by website to store information in your browser
  * used for authentication, personalization, and tracking
  * cookies saved on your client device can only be read by the website. anyone can write a secure cookie though. secure cookies are set over HTTPS
  * there are temporary cookies, persistent cookies, and third-party cookies
  * Storing states in browser cookies is good, but potentially brings up the risk of users being able to edit the cookie in some way to benefit them. To fix this there is a MAC tied to every cookie computer with the server’s secret key. 
  * better cookie authenticator makes the cookie have: capability, expiration, Hash(server secret, capability, expiration).
* Kerberos
  * many to many authentication protocol design. 
  * requirements of many to many authentication
    * security - must be secure against attacks by passive eavesdroppers and actively malicious attackers (including rogue users)
    * reliability - must be always available.
    * transparency - users should not notice its taking place
    * scalability - should handle lots of users and servers
  * threats in a simple many to many authentication system
    * user impersonation, network address impersonation, eavesdropping, tampering and replay
    * solution to this was to build a model with a trusted third party
  * Important ideas in Kerberos
    * short term session keys
    * proofs of identity are based on authenticators
    * symmetric crypto only
  * Problems in Kerberos
    * dictionary attacks on client master keys
    * replay of authenticators
      * 5 minute lifetimes long enough for replay
      * timestamps assume global, secure synchronized clocks
      * challenge response would make it batter
    * same user server key used for all sessions
    * double encryption of tickets
    * no ticket delegation
  * Practical uses: email, FTP, network file systems, local authentication (login, su), authentication for network protocols (rlogin, rsh, telnet), secure windowing systems

## Spam
* Open relays: an SMTP relay forwards mail to destination, can send as a list of recipients.
* SMPT header consists of to, cc, bcc, from, sender, receiver, return-path
* Open proxy - spammer must send message to each recipient through the proxy where open relay can take a list of addresses and send to all. can host an open relay on a zombie
* Bobax worm:
  * infects machines with high bandwidth, is slow spreading and hard to detect, installs hacked open really on infected zombies
* IP blacklisting is not enough. more than half of client IPs appear less than twice
* Most bots send little span regardless of how long they are alive
* IP addresses of spam sources only appear once or twice
* vast majority of spam originates from a small fraction of IP address space that most legitimate email comes from
* spammers exploit routing infrastructure by either creating short lived connection to mail relay or hijack a large chunk of unallocated “dark” space
* Spambot behavior has a strong correlation with Bobax infections. they are typically active for a short amount of time. 
* Stormbot spam architecture - work bots generate unique messages for each address, try to deliver, report results to their proxies
* countermeasures:
  * CAN-SPAM act - bans email harvesting, misleading header information, deceptive subject lines, use of proxies. requires opt-out identification of advertising, imposes up to $11k penalties. only 50 cases from 2003-2005 report. no impact on spam originating outside the US
  * SPF (Sender Policy Framework)
Process where the recipeints email gateway does a DNS query on example.com and checks the list of returned IP addresses to the one in the email.
  * Domain Keys (DKIM)
    * sender’s server has to sign email
    * recipients email gateway does a DNS query on example.com to get a public key. then attempts to verify the digital signature using the public key returned from the DNS server
  * S/MIME
    * sender obtains public key certificate from public certificate authority. senders email server applies an S/MIME digital signature to the email using the signing certificate. recipients email client will then see if the valid signature icon appears or not. 
  * DKIM and SPF don’t help with spammers creating email accounts, CAPTCHAs do.
* graylists - recipient’s mail server records triple in its database (configurable for let’s say 3 days).  first time tries to send will get busy reply, second time will let email pass.
* puzzles and captchas

##Phishing
* phishing techniques
  * use confusing URLs
  * use URL with multiple redirection
  * host phishing sites on botnet zombies
  * pharming - poison DNS tables so that victim’s address points to the phishing site
* Defenses against phishing
  * whitelist of trusted sites
  * passmark/siteKey (if you don’t recognize your personalized sitekey, don’t enter your password
  * PIN Guard - use your mouse or keyboard numbers to type letters
  * Scramble pad
  * virtual keyboard
  * Bharosa slide - on first login, user picks a symbol, on subsequent logins all letters and numbers in the PIN must be chosen using the correct symbol
* Warnings
  * active vs passive
* PwdHash - like a one password kind of deal

## Network Attacks
* Security issues in TCP/IP
  * network packets pass by and thru untrusted hosts (eavesdropping/packet sniffing)
  * IP addresses are pubic (smurf attacks)
  * TCP connection requires state (SYN flooding)
  * TCP state easy to guess (TCP spoofing and connection hijacking)
* Smurf Attack
  * is a distributed denial-of-service attack in which large numbers of Internet Control Message Protocol (ICMP) packets with the intended victim's spoofed source IP are broadcast to a computer network using an IP Broadcast address. 
* Ping of Death
  * in old Windows machine that would crash when received an ICMP packet with payload over 64k
* Teardrop and Bonk
  * changing the offset field of a TCP fragment to either overlap values (bad/old implementation of TCP/IP stack would crash when attempting to re-assemble) or to very large values so that the target system will crash
* LAND
  * single packet denial of service attack triggered when ip packet with source address and destination address are the same. SYN flag set. fixed with loopback implementation
* TCP handshake
  1. SYN from client
  2. SYNACK from server
  3. ACK from client
* SYN flooding
  * an example of an asymmetric vulnerability that causes a DoS attack
* Preventing DoS 
  * it is caused by asymmetric state allocation
  * cookies allow server to remain stateless until client produces to server the cookie with its ACK.
  * Anti-spoofing cookies basic patter
    * client sends request to server
    * server responds with hashed connection data and doesn’t allocate any resource yet
    * client confirms by returning cookie
    * server reconfirms the cookie is correct
  * Passive defense: random deletion
    * if SYN queue is full, delete random entry of half-open connections
      * legitimate connections have a change to complete
      * fake addresses will eventually be deleted
    * easy to implement
