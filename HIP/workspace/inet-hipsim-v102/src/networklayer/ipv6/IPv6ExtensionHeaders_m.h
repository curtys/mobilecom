//
// Generated file, do not edit! Created by opp_msgc 4.1 from networklayer/ipv6/IPv6ExtensionHeaders.msg.
//

#ifndef _IPV6EXTENSIONHEADERS_M_H_
#define _IPV6EXTENSIONHEADERS_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "IPv6Address.h"
#include "IPv6Datagram.h"
// }}



/**
 * Class generated from <tt>networklayer/ipv6/IPv6ExtensionHeaders.msg</tt> by opp_msgc.
 * <pre>
 * class IPv6HopByHopOptionsHeader extends IPv6ExtensionHeader
 * {
 * }
 * </pre>
 */
class IPv6HopByHopOptionsHeader : public ::IPv6ExtensionHeader
{
  protected:

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv6HopByHopOptionsHeader&);

  public:
    IPv6HopByHopOptionsHeader();
    IPv6HopByHopOptionsHeader(const IPv6HopByHopOptionsHeader& other);
    virtual ~IPv6HopByHopOptionsHeader();
    IPv6HopByHopOptionsHeader& operator=(const IPv6HopByHopOptionsHeader& other);
    virtual IPv6HopByHopOptionsHeader *dup() const {return new IPv6HopByHopOptionsHeader(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, IPv6HopByHopOptionsHeader& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, IPv6HopByHopOptionsHeader& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>networklayer/ipv6/IPv6ExtensionHeaders.msg</tt> by opp_msgc.
 * <pre>
 * class IPv6RoutingHeader extends IPv6ExtensionHeader
 * {
 *     @customize(true);
 *     unsigned short routingType;
 *     unsigned short segmentsLeft;
 *     IPv6Address address[];
 * }
 * </pre>
 *
 * IPv6RoutingHeader_Base is only useful if it gets subclassed, and IPv6RoutingHeader is derived from it.
 * The minimum code to be written for IPv6RoutingHeader is the following:
 *
 * <pre>
 * class IPv6RoutingHeader : public IPv6RoutingHeader_Base
 * {
 *   public:
 *     IPv6RoutingHeader() : IPv6RoutingHeader_Base() {}
 *     IPv6RoutingHeader(const IPv6RoutingHeader& other) : IPv6RoutingHeader_Base() {operator=(other);}
 *     IPv6RoutingHeader& operator=(const IPv6RoutingHeader& other) {IPv6RoutingHeader_Base::operator=(other); return *this;}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from IPv6RoutingHeader_Base
 * };
 * </pre>
 */
class IPv6RoutingHeader_Base : public ::IPv6ExtensionHeader
{
  protected:
    unsigned short routingType_var;
    unsigned short segmentsLeft_var;
    ::IPv6Address *address_var; // array ptr
    unsigned int address_arraysize;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv6RoutingHeader_Base&);
    // make constructors protected to avoid instantiation
    IPv6RoutingHeader_Base();
    IPv6RoutingHeader_Base(const IPv6RoutingHeader_Base& other);
    // make assignment operator protected to force the user override it
    IPv6RoutingHeader_Base& operator=(const IPv6RoutingHeader_Base& other);

  public:
    virtual ~IPv6RoutingHeader_Base();
    virtual IPv6RoutingHeader_Base *dup() const {throw cRuntimeError("You forgot to manually add a dup() function to class IPv6RoutingHeader");}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned short getRoutingType() const;
    virtual void setRoutingType(unsigned short routingType_var);
    virtual unsigned short getSegmentsLeft() const;
    virtual void setSegmentsLeft(unsigned short segmentsLeft_var);
    virtual void setAddressArraySize(unsigned int size);
    virtual unsigned int getAddressArraySize() const;
    virtual IPv6Address& getAddress(unsigned int k);
    virtual const IPv6Address& getAddress(unsigned int k) const {return const_cast<IPv6RoutingHeader_Base*>(this)->getAddress(k);}
    virtual void setAddress(unsigned int k, const IPv6Address& address_var);
};

/**
 * Class generated from <tt>networklayer/ipv6/IPv6ExtensionHeaders.msg</tt> by opp_msgc.
 * <pre>
 * class IPv6FragmentHeader extends IPv6ExtensionHeader
 * {
 *     unsigned short fragmentOffset;
 *     unsigned int identification;  
 *     bool moreFragments; 
 * }
 * </pre>
 */
class IPv6FragmentHeader : public ::IPv6ExtensionHeader
{
  protected:
    unsigned short fragmentOffset_var;
    unsigned int identification_var;
    bool moreFragments_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv6FragmentHeader&);

  public:
    IPv6FragmentHeader();
    IPv6FragmentHeader(const IPv6FragmentHeader& other);
    virtual ~IPv6FragmentHeader();
    IPv6FragmentHeader& operator=(const IPv6FragmentHeader& other);
    virtual IPv6FragmentHeader *dup() const {return new IPv6FragmentHeader(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned short getFragmentOffset() const;
    virtual void setFragmentOffset(unsigned short fragmentOffset_var);
    virtual unsigned int getIdentification() const;
    virtual void setIdentification(unsigned int identification_var);
    virtual bool getMoreFragments() const;
    virtual void setMoreFragments(bool moreFragments_var);
};

inline void doPacking(cCommBuffer *b, IPv6FragmentHeader& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, IPv6FragmentHeader& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>networklayer/ipv6/IPv6ExtensionHeaders.msg</tt> by opp_msgc.
 * <pre>
 * class IPv6DestinationOptionsHeader extends IPv6ExtensionHeader
 * {
 *     @customize(true);
 * };
 * </pre>
 *
 * IPv6DestinationOptionsHeader_Base is only useful if it gets subclassed, and IPv6DestinationOptionsHeader is derived from it.
 * The minimum code to be written for IPv6DestinationOptionsHeader is the following:
 *
 * <pre>
 * class IPv6DestinationOptionsHeader : public IPv6DestinationOptionsHeader_Base
 * {
 *   public:
 *     IPv6DestinationOptionsHeader() : IPv6DestinationOptionsHeader_Base() {}
 *     IPv6DestinationOptionsHeader(const IPv6DestinationOptionsHeader& other) : IPv6DestinationOptionsHeader_Base() {operator=(other);}
 *     IPv6DestinationOptionsHeader& operator=(const IPv6DestinationOptionsHeader& other) {IPv6DestinationOptionsHeader_Base::operator=(other); return *this;}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from IPv6DestinationOptionsHeader_Base
 * };
 * </pre>
 */
class IPv6DestinationOptionsHeader_Base : public ::IPv6ExtensionHeader
{
  protected:

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv6DestinationOptionsHeader_Base&);
    // make constructors protected to avoid instantiation
    IPv6DestinationOptionsHeader_Base();
    IPv6DestinationOptionsHeader_Base(const IPv6DestinationOptionsHeader_Base& other);
    // make assignment operator protected to force the user override it
    IPv6DestinationOptionsHeader_Base& operator=(const IPv6DestinationOptionsHeader_Base& other);

  public:
    virtual ~IPv6DestinationOptionsHeader_Base();
    virtual IPv6DestinationOptionsHeader_Base *dup() const {throw cRuntimeError("You forgot to manually add a dup() function to class IPv6DestinationOptionsHeader");}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

/**
 * Class generated from <tt>networklayer/ipv6/IPv6ExtensionHeaders.msg</tt> by opp_msgc.
 * <pre>
 * class IPv6AuthenticationHeader extends IPv6ExtensionHeader
 * {
 * }
 * </pre>
 */
class IPv6AuthenticationHeader : public ::IPv6ExtensionHeader
{
  protected:

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv6AuthenticationHeader&);

  public:
    IPv6AuthenticationHeader();
    IPv6AuthenticationHeader(const IPv6AuthenticationHeader& other);
    virtual ~IPv6AuthenticationHeader();
    IPv6AuthenticationHeader& operator=(const IPv6AuthenticationHeader& other);
    virtual IPv6AuthenticationHeader *dup() const {return new IPv6AuthenticationHeader(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, IPv6AuthenticationHeader& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, IPv6AuthenticationHeader& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>networklayer/ipv6/IPv6ExtensionHeaders.msg</tt> by opp_msgc.
 * <pre>
 * class IPv6EncapsulatingSecurityPayloadHeader extends IPv6ExtensionHeader
 * {
 *     int spi;
 * }
 * </pre>
 */
class IPv6EncapsulatingSecurityPayloadHeader : public ::IPv6ExtensionHeader
{
  protected:
    int spi_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv6EncapsulatingSecurityPayloadHeader&);

  public:
    IPv6EncapsulatingSecurityPayloadHeader();
    IPv6EncapsulatingSecurityPayloadHeader(const IPv6EncapsulatingSecurityPayloadHeader& other);
    virtual ~IPv6EncapsulatingSecurityPayloadHeader();
    IPv6EncapsulatingSecurityPayloadHeader& operator=(const IPv6EncapsulatingSecurityPayloadHeader& other);
    virtual IPv6EncapsulatingSecurityPayloadHeader *dup() const {return new IPv6EncapsulatingSecurityPayloadHeader(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSpi() const;
    virtual void setSpi(int spi_var);
};

inline void doPacking(cCommBuffer *b, IPv6EncapsulatingSecurityPayloadHeader& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, IPv6EncapsulatingSecurityPayloadHeader& obj) {obj.parsimUnpack(b);}


#endif // _IPV6EXTENSIONHEADERS_M_H_
