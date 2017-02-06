# Networking
various networking related notes, some from classes, some from my own personal
readings.

# Networking basics

OSI 7-Layer Model

Layer Name | Description | Unit| Examples
--- | --- | --- | ---
Application|Data generation|Data|FTP,HTTP,SMTP
Presenation|Encryption & formatting|Data|JPEG,MPEG,GIF
Session|Establish connection|Data|Apple Talk
Transport|Delevery & sequence|Segments|UDP,TCP
Network|Routing to destination|Packets|IP
Data Link|Locak network|Frame|ARP,EthernetmPPP
Physical|Access media|Bits|Ethernet|10Base-T,1000Base-T,USB

### General Notes
* a socket is just a communication endpoint
* network topology: the arragement of the various elements (links, nodes, etc.) of a computer network. 
   * physical vs logical topology
* network byte order is big-endian (MSB first)
