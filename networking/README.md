# Networking
various networking related notes, some from classes, some from my own personal
readings.

### General Notes
* a socket is just a communication endpoint
* network topology: the arragement of the various elements (links, nodes, etc.) of a computer network. 
  * physical vs logical topology
  * examples:
    * point-to-point
    * bus - linear, distributed
    * star - extended, distributed
    * ring
    * mesh; full/partially connected
    * hybrid
    * daisy chain
* network byte order is big-endian (MSB first)
  ![hosttonetwork](https://github.com/comychitz/knowledge/blob/master/networking/img/hosttonetwork.png)

### Sockets
The stages of creating a socket and connecting on that socket as a client/server.
![serverclientsockets](https://github.com/comychitz/knowledge/blob/master/networking/img/networking.png)


## Network Security
For network security see this page -> [networksecurity](https://github.com/comychitz/knowledge/blob/master/networking/networksecurity.md)

## Layer-by-layer Notes
OSI 7-Layer Model

Layer Name | Description | Unit| Examples
--- | --- | --- | ---
Application|Data generation|Data|FTP,HTTP,SMTP
Presenation|Encryption & formatting|Data|JPEG,MPEG,GIF
Session|Establish connection|Data|Apple Talk
Transport|Delevery & sequence|Segments|UDP,TCP
Network|Routing to destination|Packets|IP
Data Link|Local network|Frame|ARP,EthernetmPPP
Physical|Access media|Bits|Ethernet|10Base-T,1000Base-T,USB

###Transport Layer
interaction between transport and network layers, overview. 
* transport layer provides logical communication between processes
* network layer provides logical communication between hosts
* transport layer protocols are implemented in the end systems but not in network routers

connection-oriented and connectionless multiplexing and demultiplexing. 
* demultiplexing is done by the destination and is the job of delivering the data in a transport-layer segment to the correct socket
* multiplexing is done at the source and is the job of gathering data chunks at the source host from different sockets, encapsulating each data chunk with
* header information to create segments, and passing the segments to the network layer

* Connectionless/UDP multiplexing/demultiplexing is very simple. The transport layer segment includes the application data, the source port number, the destination port numbers, length and checksum.
* Connection-oriented/TCP multiplexing/demultiplexing. The segment in the transport layer of the source sends the four values in the connection-request segment: the source port number, the source IP address, the destination port number and the destination IP address.

UDP services, pro and cons of connectionless transport 
* aside from multiplexing and demultiplexing and some light error checking, UDP adds nothing to IP. 
* some reasons UDP is used: 
  * Finer application-level control over what data is sent and when.
  * No connection establishment. no delay to establish connection. DNS likes this.
  * No connection state. UDP can then support more clients
  * Small packet header overhead. only 8 bytes, versus TCPs 20.
* UDP has no congestion control
* it is possible to have reliable data transfer when using UDP if the reliability is built into the application itself.

Principles of reliable data transfer (retransmission, feedback, error detection, numbering, timeouts), stop and-wait, Go-Back-N, selective repeat
* Automatic Repeat reQuest (ARQ) protocols require three additional protocol capabilities to handle bit errors: 
  * Error detection - checksum
  * Receiver Feedback - positive or negative acknowledgment 
  * retransmission - a packet that has an error will be resent by the sender
* Stop and wait protocols are when the protocol consists of steps where we are waiting for acknowledgement.
* Sequence numbering is used to allow the receiver to know if a packet is a retransmission or not. This is used to solve the problem that there is corruption in the acknowledgement stage.
* Timeout - using a timer to recover from lost data or for acknowledgement packets
* Go-Back-N is a protocol used for pipelined error recovery. The basic idea is that the sender is allowed to transmit multiple packets without waiting for an  acknowledgement, but the number of packets it sends in a row is constrained to some number N. Also called the sliding window protocol. GBN has the problem when the window size and bandwidth delay are both large. Many packets are in the pipeline and if one has an error then a large number of packets are retransmitted. Selective repeat avoids unnecessary retransmissions by having the sender retransmit only those packets that it suspects were received in error at the receiver. We use a window size of N like in GBN, but the receiver now individually acknowledges packets, thus both sender and receiver both have windows. A problem with SR is the synchronization between windows. Also large windows is a problem here too. TCP is classified as a hybrid of GBN and SR.

timeout and RTT, timeout and fast retransmit, flow control 
* TimeoutInterval = EstimatedRTT + 4 * DevRTT
* DevRTT is the RTT variation, which is an estimate of how much SampleRTT typically deviates from EstimatedRTT. 
* EstimatedRTT = 0.875 * EstimatedRTT + 0.125*SampleRTT (weighted combination of the previous value of EstimatedRTT and the new value for SampleRTT. 
* fast retransmit - retransmitting the missing segment before the segment’s timer expires. The sender is able to do this whenever it receives three ACKs (which indicates that the packet after the three ACKs has been lost).
* Flow control is a speed matching service - matching the rate at which the sender is sending against the rate at which the receiving application is reading. TCP uses a variable called the receive window which is used to give the sender an idea of how much free buffer space is available at the receiver.

congestion control principles and approaches 
* Congestion - too many sources attempting to send data at too high a rate. 
* Costs of congestion include:
  * Large queueing delays are experienced as the packet-arrival rate nears the link capacity.
  * the sender must perform retransmissions in order to compensate for dropped packets due to buffer overflow.
  * unneeded retransmissions by the sender in the face of large delays may cause a
  * router to use its link bandwidth to forward unneeded copies of a packet.
  * its possible two hosts throughput may go to zero
  * when a packet is dropped along a path, the transmission capacity that was used at each of the upstream links to forward that packet to the point at which is dropped ends up having been wasted
* Approaches:
  * end-to-end congestion control - network layer provides no explicit support to the transport layer for congestion control purposes. TCP uses this approach since its in the transport layer.
  * network-assisted congestion control - network layer components (routers) provide explicit feedback to the sender regarding the congestion state in the network. Two ways: direct feedback using choke packets, or a router marks/updates a field in a packet flowing from sender to receiver indicating congestion.

TCP congestion control: principles of congestion estimation (lost  segment, acknowledgment, probing), slow start, congestion avoidance, fast recovery. TCP Reno
* The approach TCP takes is to have each sender limit the rate at which it sends  traffic into its connection as a function of perceived network congestion. It  uses a variable known as the congestion window. The amount of unacknowledged data at a sender may not exceed the minimum of the congestion window and the receive window (LastByteSent - LastByteAcked <= min{cwnd, rwnd}
* But how does a TCP sender know what rate to send at? We use the following techniques:
  * lost segment - a lost segment implies congestion, and hence, the TCP sender’s   rate should be decreased when a segment is lost
  * acknowledged segment - an acknowledged segment indicates that the network is delivering the sender’s segments to the receiver, and hence, the sender’s rate can be increased when an ACK arrives for a previous unacknowledged segment.
  * Bandwidth probing - TCP’s strategy for adjusting its transmission rate is to increase its rate in response to arriving ACKs until a loss event occurs, at which point, the transmission rate is decreased.
* Above is the overview of TCP congestion control. Now we discuss the TCP congestion control algorithm:
  * Slow start - is the first state of the algorithm and starts off slow by giving cwnd a small value (1 MSS) and increase it by 1 MSS every time an ACK comes in. This is exponential though. When it looses a segment before the threshold is reached it starts over at 1 MSS and threshold to half the cwnd.
  * If the threshold is reached or a loss occurred then it transitions into congestion avoidance mode.
  * Congestion Avoidance - Congestion avoidance increases the congestion window linearly. If a timeout occurs it is the same as in the slow state. But if a   triple ACK occurs it halves the cwnd and threshold becomes half cwnd. Then it enters Fast Recovery.
  * Fast recovery - in fast recovery the value of condo is increase by 1 MSS for every duplicate ACK received for the missing segment that caused TCP to enter the fast recovery state. Eventually, when an ACK arrives for the missing segment, TCP enters the congestion avoidance state. If a timeout occurred, it will go to slow start state and do the same thing that it did in the previous loss scenarios, set cwnd to 1 MSS and threshold to half condo
* TCP reno is the newest version of TCP and incorporated fast recovery.
* TCP used by applications that want packet retransmission and packet reordering and are willing to put up with congestion control. i.e. email, http, ftp
* UDP used by applications that are not willing to put up with congestion control and dont need packet retransmission and packet reordering. i.e. streaming, VoIP, video conferencing, gaming

###Network Layer
DNS: servies, overview, hierarchical architecture
* DNS is (1) a distributed database implemented in a hierarchy of DNS servers and (2) it is an application layer protocol that allows hosts to query the distributed database.
* DNS provides services other than translating host names to IP addresses:
  * Host aliasing - a host with a complicated name can have one or more alias names. It takes the longer (canonical hostname) and makes it an easy one like cnn.com  or www.cnn.com 
  * Mail server aliasing - allows for mnemonic email addresses
  * Load distribution - busy sites can be distributed among many different servers
* Hierarchical architecture
  * If there was only a centralized DNS server then we would have the following problems: a single point of failure, traffic volume, distant centralized database, maintenance. 
* Three main classes of hierarchy: Root DNS servers, Top Level domain servers, Authoritative DNS servers (for each website), local DNS (for universities, or local ISPs).

Link layer addressing: MAC addresses, ARP protocol (overview), sending a datagram off the subnet.
* link-layer addresses are called LAN addresses, physical addresses or MAC addresses. They are 6 bytes long giving 248 possibilities. No two MAC addresses are the same. IEEE manages the address space.
* ARP - address resolution protocol is designed to resolve an IP address to a MAC address. It takes in a corresponding IP address as an input and returns the corresponding MAC address. ARP is considered a protocol in between the link and network layer. It has both link layer addresses and network layer addresses.
* To send from one subnet to another we must send the datagram to the first hop router (find the MAC address of that using ARP), then the router uses the forwarding table to find out that the datagram is to be forwarded using the specific routing interface. Then it send the datagram into subnet 2 to the correct host using ARP once again.

connection and connectionless network layers, transport layer vs  network layer services, virtual circuit vs datagram networks, virtual circuit   (connection state, addressing, connection phases), datagram networks (forwarding tables, forwarding rules)
* In the network layer the services are host-to-host, not process-to-process like in the transport layer.
* Connection and connectionless network layer services:
  * network layer services provide either a host-to-host connectionless service or connection service, but not both.
  * Virtual circuits are connection-oriented service in the network layer and datagram networks provide only connectionless service
* Virtual Circuits
  * A VC consists of (1) a path (a series of links and routers) between source and destination hosts, (2) VC numbers, one for each link along the path, and (3) entries in the forwarding table in each router along the path. A packet belonging to a virtual circuit will carry a VC number in its header. As a packet travels through a path each routering interface (both incoming and outgoing) must replace the VC number. The new VC number is obtained from the forwarding table. 
  * In a VC network, the network’s routers must maintain connection state information for the ongoing connections. That is, each time a new connection is establish across a router, a new connection entry must be added to the router’s forwarding table, and each time a connection is released it is removed from the routing table.
  * Three phases in a virtual circuit:
     * VC setup - in this phase the sending transport layer contacts the network  layer, specifies the receiver’s address, and waits for the network to set up the VC. The network layer determines the path between the sender and reciever, all the links and routers, determines the VC number for each link and adds an entry in the forwarding table in each router along the path.
     * Data transfer - once it has been set up, data starts to be flowed through the path.
     * VC teardown - when the sender or receiver informs the network layer of its desire to terminate the VC, the network layer will then update all forwarding tables for routers on the path letting them know the VC no longer exists.
* Datagram Networks:
   * in a datagram network each time an end system wants to send a packet it stamps the packet with he address of the destination end system and send the packet into the network routers in datagram networks maintain no connection state information, they nevertheless maintain forwarding state information in their forwarding tables. The time that these forwarding state information changes is relatively slow in comparison to VCs.

Routers: architecture and components, input processing, switching, output processing, queueing 
* Architecture and components, 4 main components:
   * Input ports - input ports perform several functions: it performs the physical layer function of terminating an incoming physical link. It also performs link layer functions needed to interoperate with the link later. And it also performs the lookup function (consulting the look up table to see which output port a packet will be forwarded to via the switching fabric).
   * Switching fabric - connects the router’s input ports and output ports
   * Output ports - stores the packets received from the switching fabric and transmits these packets on the outgoing link by performing the necessary link-layer and physical-layer functions.
   * Routing processor - this executes the routing protocols and is done in software by an onboard CPU.
   * Forwarding vs routing functions: forwarding is done by input ports, switching fabric and output ports (router forwarding plane). routing functions are done by the routing processor (router control plane). 
   * Input processing: consists of three main steps: line termination, data link processing (protocol, decapsulation), and lookup, forwarding & queueing. Then it is sent to the switching fabric.
   * Switching: switching can be done in several ways: switching via memory (under direct control of the CPU), switching via a bus, and switching via an interconnection network (crossbar).
   * Output processing: includes three main steps: queueing (buffer management), data link processing (protocol, encapsulation) and line termination (link and network layer functions).
   * Queueing: queueing occurs in both the input and output ports of a router. It here where there is packet loss. 

ICMP (overview) Internet Control Message Protocol
* Is used by hosts and routers to communicate network-layer information to each other, for network layer information gathering and reporting. The most typical use for ICMP is for error reporting. Ping & traceroute use ICMP.
* ICMP lies just above IP, as ICMP messages are carried inside IP datagrams.

Graph model, shortest path, global vs decentralized routing algorithms, Link State protocol, Distance vector, comparison LS vs DS, Hierarchical routing
* Link state algorithm, the network topology and all link costs are know. In a decentralized routing algorithm the calculation of the least cost path is done in an iterative, distributed manner.
* Link-State Algorithm
    * All the info about costs are found by having each node broadcast link-state packets to all other nodes in the network, with each link-state packet containing the identities and costs of its attached links. Then we run Dijkstra;s shortest path algorithm for each router. Runs in O(n2) time. 
* The Distance Vector Routing Algorithm
    * the DV algorithm is iterative, asynchronous and distributed. It is distributed in that each node receives some information from one or more of its directly attached neighbors, performs a calculation, and then distributes the result of its calculation back to its neighbors. It is iterative in that this process continues on until no more information is exchanged between neighbors. It is asynchronous in that it does not require all of the nodes to operate in lockstep with each other. The basic idea is as follows: each node is initialized with an estimate of the leas-cost path from itself to another node. Then for each iteration a node updates its distance-vector estimate when it either sees a cost change one of its directly attached links or receives a distance-vector update from some neighbor. 
* LS vs DV: message complexity, speed of convergence, robustness. Neither algorithm wins over the other, both are used in the internet today.
* Hierarchical routing
    * So far we have been considering a router to represent a set of routers  running the same protocol, but that’s not how it is in real like. Because of scale and administrative autonomy we have to organize routers into autonomous systems (ASs). Routers within the same AS running the same routing algorithm. 
    * The routing algorithm within an AS is referred to as an intra-autonomous system routing protocol.
    * Groups of ASs are interconnected by gateway routers, usually  more than one of them. The gateways then use inter-AS routing protocols. Since inter-AS routing protocol involves communicating between two ASs, the two communicating ASs must run the same inter-AS routing protocol. in the internet all ASs run the same inter-AS routing protocol BPG4.

Routing in the Internet - intra-AS routing, RIP and OSPF (overview), inter-AS routing, BPG basics, BPG route selection, routing policy, why inter and intra-AS routing
* Intra-AS routing (also known as interior gateway protocols)
    * RIP - Routing Information protocol is a distance-vector protocol that operates in a manner very close to the idealized DV protocol. It uses hop count as a cost metric. Max cost in a path is limited to 15, thus limiting the use of RIP to systems less than 15 hops in diameter. Routing updates are exchanged between neighbors about every 20 seconds using an RIP response message (contains a list of up to 25 destination subnets within the AS, as well as the sender’s distance to each of those subnets). Response messages are also known as RIP advertisements. Each router maintains a RIP table known as a routing table.
   * OSPF - Open Shortest Path First is a link-state protocol that uses flooding of link-state information and Dijkstra’s algorithm. A router constructs a complete graph of the entire AS then locally runs Dijkstra’s algorithm to determine a shortest path tree to all subnets, with itself as the root node. OSPF has some advances embodied into it: security, multiple same-cost pants, integrated support unicast and multicast routing, and support for hierarchy within a single routing domain. 
*Inter-AS Routing
   * BGP - The Border Gateway Protocol version 4. It is an essential part of the internet as it is the de facto protocol and is responsible for glueing everything together. 
   * Basics - BGP works over TCP. A BGP session connects two BPG peers (in the same or different AS) to send BGP messages back and forth. Essentially BGP allows each AS in a session to learn which destination are reachable via its neighboring ASs. In BGP, destination are not hosts, but instead are CIDRized prefixes, each prefix representing a subnet attached to AS2. Then the peers
   use the prefixes to find out possible paths.
   * BGP route selection - Using the prefixes a router can learn that there is more than one possible route. If this is so BGP uses the following elimination rules until one route remains:
      * Routers are assigned a local preference value as one of their attributes.
      * Routes with highest local preference values are selected
      * From the remaining routes (with the same local preference), the route with the shortest AS-PATH is selected.
      * Of those that are the same length and local preference, the route with thecosts NEXT-HOP router is selected.
      * If more than one route still remains, the router uses BGP identifiers to select the route. 
   * BGP routing policy - We control the manner in which BGP routes are advertised. For customer/provider relationships the customer would not advertise that it can send data to any other destination except itself. Thus causing the provider to never route data through a customer to somewhere.
* Why are there different inter-AS and intra-AS protocols? Three main reasons:
    * Policy - traffic coming from a specific AS may not be able to pass through another AS.
    * Scale - the ability of a routing algorithm and its data structure to scale to handle routing to/among large numbers of networks.
    * Performance - quality of the routes in inter-AS routing is not as much of a concern. Sometimes in intra-AS routing we are concerned with the performanceof a route.

Broadcast routing, uncontrolled and controlled flooding, spanning tree, multicast routing, multicast tree
* Broadcast routing - the network layer provides a service of delivering a packet sent from a source node to all other nodes in a network.
* Uncontrolled Flooding - flooding is where the source nodes sends a copy of the pack to all of its neighbors. This has two major flaws:     
    * 1 - if there is a cycle in the network then some broadcast packets will cycle indefinitely. 
    * 2 -  When a node is connected to more than two nodes, it will create and forward multiple copies of the broadcast packet, resulting in an eventual endless  multiplication of broadcast packets called a broadcast storm.
* Controlled flooding - solves the two problems using different approaches
* To solve the issue of a broadcast storm we can use sequence-number-controlled flooding or reverse path forwarding (RPF). In sequence number controlled flooding each source node puts its address and broadcast sequence number into the broadcast packet and send the packet to all of its neighbors. Each node has a list of the sequence numbers and only accepts it if the packet is not in the list. In RPF, when a router receives a broadcast packet with a given source address, it transmits the packet on all of its outgoing links only if the packet arrived on the link that is on its own shortest unicast path back to the source. 
* To solve the problem of transmitting redundant packets we use minimum spanning tress. An MST is a graph that includes all the nodes but only edges that don't make a cycle, but still connect all the nodes.
* Multicast route - enables a single source node to send a copy of a packet to a subset of the nodes. Thus we need to make a group of who is the subset of nodes to send a packet to. Two approached for finding the multicast tree for a multicast routing problem
* Multicast routing using a group-shared tree - based on building a tree that includes all edge routers with attached hosts belonging to the multicast group.
* Multicast routing using a source-based tree - Group shared tree multicast routing constructs a single, shared routing tree to route packets from all senders, the source-based tree constructs a multicast routing tree for each source in the multicast group. 

Multiple classes of service (motivation, scheduling, policing), DiffServ
* Motivation
    * Insight 1: Packet marking allows a router to distinguish among packets belonging to difference classes of traffic. 
    * Insight 2 - it is desirable to provide a degree of traffic isolation among classes so that one class not adversely affect by another class of traffic that misbehaves.
    * Insight 3 - While providing isolation among classes or flows, it is desirable to use resources (link bandwidth and buffers) as efficiently as possible. 
* Scheduling Mechanisms - FIFO, Priority queueing, Round Robin and weighted fair queueing
    * FIFO - first in first out
    * Priority Queueing - packets are classified into priority classes at the output queue, each class with its own queue. We will transmit a packet from the highest priority class that has a nonempty queue.
    * Round robin works the same way as priority queueing, however, it alternates between sending classes. For example, send a class 1 packet, send a class 2 packet, send a class 1 packets, send a class 2 packet, etc….
    * Weighted fair queueing works like round robin but each class may receive a differential amount of service in any interval of time, which is determined by the weight for each class.
   * Policing - the regulation of the rate at which a class or flow is allowed to inject packets into the network. Three important policing criteria are:
      * average rate, peak rate, and burst size.
   * Leaky bucket - we have a bucket which holds up to b tokens and generates r  tokens/second. It can only add tokens if it is less than b token in the bucket. Each packet that comes into the network must take a token in the bucket. If it is empty a packet must wait for a token to arrive. This serves to limit the long-term average rate at which packets can enter a network. Leaky bucket with weighted fair queueing = provable maximum delay in a queue. 
   * Diffserv -  Differentiated services provides service differentiation, the ability to handle different classes of traffic in different ways within the internet in a scalable manner. Two sets of functional elements in Diffserv: edge functions - packet classification and traffic conditioning, and core function - forwarding. Result of DiffServ (1) QoS does not require virtual circuits, and (2) ISPs to divide whether to use only internal or through peering & transit and whether to charge or not.

###Link Layer and Local Area Networks (LAN)
services, adapter and interfaces
* two types of network links: point-to-point (single sender and receiver) and broadcast links (multiple senders and receivers on the same broadcast channel).
* services provided by the link layer:
    * Framing - putting network layer datagrams into a link layer frame before transmission over the link.
    * Link access - rules by which a frame is transmitted onto the link
    * Reliable Delivery - when a link layer protocol provides reliable delivery service, it guarantees to move each network-layer datagram across the link without error.
    * Error detection and correction - receivers not only detect when bit errors have occurred in the farebeat also determines exactly where in the frame theerrors have occurred.
   * link layer is implemented in a network adapter, also known as a network interface card. at the heart of the network adapter is the link layer controller, usually a single, special-purpose chip that implements many of  the link-layer services.

error detection and correction principles, checksum and CRC
 * in the link layer error detection and correction are done at the bit level.
 * three techniques for error detection and correction:
    * Checksum - in checksumming techniques we tree the d bits as a sequence of k-bit integers. The Internet checksum method is to sum these k-bit integers and use the resulting sum s the error-detection bits. checksumming is used in the transport layer.
    * Cyclic redundancy check (CRC) - In CRC we treat the bits as a polynomial whose coefficients are 0 or 1. then we perform polynomial arithmetic (more specifically, we perform a division in modulo-2 arithmetic to see if the result is non zero, meaning there is an error).

MAC protocols: taking turns and random access protocols, TDMA and FDMA, slotted aloha, aloha, carrier sensing, collision detections
* how to coordinate the access of multiple sending and receiving nodes to a shared broadcast channel is know as the multiple access problem. Three main ways to do this:
    * Channel Partitioning protocols - split up a broadcast channel’s bandwidth among the nodes.
    * TDMA - divides time into time frames and each time frame into N time slots. Each time slot is then assigned to one of the nodes. Nodes will then send packets only during its assigned time slot (usually only able to send one packet).Two major drawbacks (1) a node is limited to an average rate of R/N bps, even when its the only node to send (2) when its the only node it still
   needs to wait for its time to transmit.
   * FDMA - splits the R bps channels into different frequencies (each with a bandwidth of R/N). same advantages and drawbacks as TDMA. It avoids collisions and divides the bandwidth fairly, however, a node is limited to its bandwidth (R/N) even when its the only node with packets to send.
   * CDMA - code division multiple access - CDMA assigns codes (like times or frequencies) to nodes. if the codes are chosen carefully, then different nodes can transmit simultaneously and have their respective receiver receive a sender’s encoded data bits.
   * Random access protocols - In a random access protocol, a transmitting node always transmits at the full rate of the channel, R bps. When there is a collision, each node involved in the collision repeatedly retransmits its frame until its frame gets through without a collision. When a collision occurs it doesn’t retransmit right away. It waits a random amount of time (independent of each other).
   * Slotted ALOHA - assumptions: frames have the same size, time divided into equal size, nodes start to transmit only at the beginning of slots. operation: when there is a new frame, attempt to transmit. if there is no collision we are good, if there is collision each node will retransmit in the next slot with probability of p until there is a success. pros: single active node can continuously transmit at full rate, highly decentralized, simple. cons: collisions, wastes slots, idle slots, clock synchronization
   * ALOHA - without the slots. transmission begins right away with probability p. there is higher probability of collision without the slots. less efficiency then slotted ALHOA.
   * CSMA - Carrier Sense Multiple Access - two important rules used in CSMA (1) listen before speaking (2) if someone else being talking at the same time, stop talking. Collision detection still occurs because propagation delay means two nodes may not hear each other’s transmission. when there is collision channel resource is wasted
   * CSMA/CD - collisions are detected within a short time. colliding transmission are aborted, reducing channel wastage. 
   * collision detection - easy in wired LANS (measure signal strengths, compare transmitted and received signals), but not in wireless LANs (received signal strength is overwhelmed by local transmission strength).
* Taking-turns protocols
    * Polling protocol - required one of the nodes to be designated as a master node. The master node polls each of the nodes in a round robin fashion. eliminated the collisions and empty slots in random access protocols. two drawbacks: polling delay, and if the master node fail the entire channel is inoperative.
    * Token passing protocol - in this protocol there is a special frame known as the token, which is exchanged in some specific order (a ring). when a node receives a token it will hold on to the token until it has no   more packets to transmit or it has sent a certain maximum amount of packets. token passing is decentralized and highly efficient.

switched local area networks: MAC addressing and ARP, ethernet (hub and switches), link layer switches, and switches vs routers
* MAC addressing and ARP already covered above.
* Ethernet
    * Hub -  a physical layer device that acts on individual bits rather than frames. When a pit arrives from one interface, the hub simply re-creates the bit, boosts its energy strength, and transmits the bit onto all the other interfaces. Ethernet with a hub-based star topology is also a broadcast LAN. No CS or CD in a hub. 
   * Switch - is not only “collision-less” but is also a bona-fide store and forward packet switch. Switches can receive packets from multiple lines at the same time, with no collisions. It determines where the packet should go, and only sends it to that line. Switches can also transmit packets on multiple lines at the same time. switches queue packets as needed. switches drop packets when its queue fills up.
   * Switches vs Routers - both of them are store-and-forward packet devices, however, a switch forwards packets using MAC addresses. A router is a layer 3 packet switch, a switch is a layer 2 packet switch. Routers provide a more robust isolation of traffic, control broadcast storms, and use more “intelligent” routes among the hosts in a network. Switch topologies are limited to a spanning tree. switches are plug in play, can provide high filtering and forwarding rates. 
   
architecture, 802.11 MAC protocol, RTS and CTS
* architecture - base stations, access points, SSIDs, Wifi Jungle, beacon  frames (APs send out become frames which includes its SSID and MAC address, then devices can use these beacon frames through active or passive scanning to find APs in its range).
* 802.11 MAC protocol
   * uses CSMA/CA. uses collision avoidance instead of collision detection. because wireless networks have higher bit error rates, we use link layer acknowledgement/retransmission (ARQ) schemes.
   * collision avoidance method 1: uses truncated binary exponential backoff in conjunction with carrier sensing. 
   * collision avoid method 2: using RTS and CTS indicate desire to transmit a packet using a small RTS (request to transmit) packet. use carrier sensing to determine when to send RTS packets. if RTS does collide access point sends out a clear to transmit (CTS) to all    users, then the one who sent the RTS transmits its data.
