Ex.No:11 STUDY OF IPV6 ADDRESSING & SUBNETTING
Date:
AIM:
To Study the IPV6 Addressing and Subnetting
What is IPv6:
As the number of internet devices—also known as the Internet of Things (IoT)—increases around the
world, more IP addresses are needed for these devices to communicate data. Consider smartphones,
smartwatches, refrigerators, washing machines, smart TVs, and other electronic devices that require an IP
address. All of these devices are now linked to the internet and have a unique IP address assigned to them. We'll
focus on IPv6, its characteristics, and why it'll be the Internet Protocol standard in this quick overview.
Before we go into the technicalities, there are a few things to know about IPv6:
1. IPv6 addresses are 128-bit (2128) and allow for 3.4 x 1038 unique IP addresses.
2. IPv6 is written in hexadecimal notation, with the colons separating eight groups of 16 bits, for a total
of 8 x 16 = 128, or bits. The following is an example of an IPv6 address:
 Syntax of IPv6 Addresses:
IPv4 addresses are represented in dotted-decimal format. The 32-bit address is divided along 8-bit
boundaries. Each set of 8 bits is converted to its decimal equivalent and separated by periods. In contrast, IPv6
addresses are 128 bits divided along 16-bit boundaries. Each 16-bit block is converted to a 4-digit hexadecimal
number and separated by colons. The resulting representation is called colon-hexadecimal.

 The Addressing Space:
The amount of memory dedicated to all potential addresses for a computational object, such as a device,
a file, a server, or a networked computer, is known as address space. A range of physical or virtual addresses
accessible to a processor or reserved for a process is referred to as address space. Each address defines an
entity's location as a unique identifier of single entities (unit of memory that can be addressed separately). Each
computer device and process is given address space on the computer, which is a piece of the processor's address
space. The address space of a processor is always constrained by the width of its address bus and registers. Flat
address space, in which addresses are expressed as continuously growing integers starting at zero, and
segmented address space, in which addresses are written as discrete segments enhanced by offsets, are the two
types of address space (values added to produce secondary addresses). Thunking is a procedure that allows
address space to be changed from one format to another in some systems.

In terms of IP address space, there has been concern that IPv4 (Internet Protocol Version 4) had not
anticipated the enormous growth of the Internet, and that its 32-bit address space would not be adequate. For
that reason, IPv6 has been developed with 128-bit address space.
Allocation of the IPv6 addressing space:

 Types of IPv6 Addresses:
Generally, IPv6 addresses is classified into 3. They are:
1. Unicast: This type is the address of a single interface. A packet forwarded to a unicast address is
delivered only to the interface identified by that address.
2. Anycast: This type is the address of a set of interfaces typically belonging to different nodes. A packet
forwarded to an anycast address is delivered to only one interface of the set (the nearest to the source
node, according to the routing metric).
3. Multicast: This type is the address of a set of interfaces that typically belong to different nodes. A
packet forwarded to a multicast address is delivered to all interfaces belonging to the set.

1. Unicast Addresses:
A unicast address identifies a single interface. When a network device sends a packet to a unicast address,
the packet goes only to the specific interface identified by that address. Unicast addresses support a global
address scope and two types of local address scopes.
A unicast address consists of n bits for the prefix, and 128 – n bits for the interface ID.
 Global unicast address—A unique IPv6 address assigned to a host interface. These addresses have a
global scope and essentially the same purposes as IPv4 public addresses. Global unicast addresses are
routable on the Internet.
 Link-local IPv6 address—An IPv6 address that allows communication between neighboring hosts that
reside on the same link. Link-local addresses have a local scope, and cannot be used outside the link.
They always have the prefix FE80::/10.
 Loopback IPv6 address—An IPv6 address used on a loopback interfaces. The IPv6 loopback address
is 0:0:0:0:0:0:0:1, which can be notated as ::1/128.
 Unspecified address—An IPv6 unspecified address is 0:0:0:0:0:0:0:0, which can be notated as ::/128.
1. Aggregatable Global Unicast Addresses:
Aggregate global unicast addresses are used for global communication. These addresses are similar in
function to IPv4 addresses under classless interdomain routing (CIDR). The following table shows their
format.

2. Geographic-Based Addresses:
Geography addresses are those determined by country of origin. This type of address is only available
in the IPv4 address category. The data address table includes a ‘scope’ and a ‘authority‘

3. Link Local Addresses:
A link-local address is a network address that is valid only for communications within the network
segment or the broadcast domain that the host is connected to. Link-local addresses are most often
assigned automatically with a process known as stateless address autoconfiguration or link-local
address autoconfiguration,[1] also known as automatic private IP addressing (APIPA) or auto-IP.

4. Site Local Addresses:

Site-local addresses are designed to be used for addressing inside of a site without the need for a global
prefix. A site-local address cannot be reached from another site. A site-local address is not automatically
assigned to a node. It must be assigned using automatic or manual configuration.
5. The Unspecified Address:
The address 0:0:0:0:0:0:0:0 is called the unspecified address. It will not be assigned to any node. It
indicates the absence of an address. One example of its use is in the Source Address field of any IPv6
packets sent by an initializing host before it has learned its own address.
6. The Loopback Address:
The IP address 127.0.0.1 is called a loopback address. Packets sent to this address never reach the
network but are looped through the network interface card only. This can be used for diagnostic
purposes to verify that the internal path through the TCP/IP protocols is working.
7. NSAP Addresses:
Short for Network Service Access Point, NSAP is an address consisting of up to 20 octets that identify
a computer or network connected to an ATM network. NSAP is defined in ISO/IEC 8348.
8. IPX Addresses:
Internetwork Packet Exchange (IPX) is the network layerprotocol in the IPX/SPXprotocol suite. IPX
is derived from Xerox Network Systems' IDP. It may act as a transport layer protocol as well.
2. Anycast Address:
An anycast address identifies a set of interfaces that typically belong to different nodes. Anycast addresses
are similar to multicast addresses, except that packets are sent only to one interface, not to all interfaces. The
routing protocol used in the network usually determines which interface is physically closest within the set of
anycast addresses and routes the packet along the shortest path to its destination.
There is no difference between anycast addresses and unicast addresses except for the subnet-router address.
For an anycast subnet-router address, the low-order bits, typically 64 or more, are zero. Anycast addresses are
taken from the unicast address space.
3. Multicast Addresses:
A multicast address identifies a set of interfaces that typically belong to different nodes. When a network
device sends a packet to a multicast address, the device broadcasts the packet to all interfaces identified by that
address. IPv6 does not support broadcast addresses, but instead uses multicast addresses in this role.
Multicast addresses support 16 different types of address scope, including node, link, site, organization, and
global scope. A 4-bit field in the prefix identifies the address scope.
The following types of multicast addresses can be used in an IPv6 subscriber access network:
 Solicited-node multicast address—Neighbor Solicitation (NS) messages are sent to this address.
 All-nodes multicast address—Router Advertisement (RA) messages are sent to this address.
 All-routers multicast address—Router Solicitation (RS) messages are sent to this address.
 Which addresses are generally used for a node?

1. Addresses of a Host:

2. Addresses of a Router:

Result :
Hence Study of IPV6 Addressing & Subnetting is completed sucessfully
