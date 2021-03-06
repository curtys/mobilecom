//
// Generated file, do not edit! Created by opp_msgc 4.1 from networklayer/ipv4/ControlManetRouting.msg.
//

#ifndef _CONTROLMANETROUTING_M_H_
#define _CONTROLMANETROUTING_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "IPAddress.h"
// }}



/**
 * Enum generated from <tt>networklayer/ipv4/ControlManetRouting.msg</tt> by opp_msgc.
 * <pre>
 * enum ManetControlType
 * {
 * 
 *     MANET_ROUTE_NO_OPTION = 0;
 *     MANET_ROUTE_UPDATE = 1;
 *     MANET_ROUTE_NOROUTE = 2;
 * }
 * </pre>
 */
enum ManetControlType {
    MANET_ROUTE_NO_OPTION = 0,
    MANET_ROUTE_UPDATE = 1,
    MANET_ROUTE_NOROUTE = 2
};

/**
 * Class generated from <tt>networklayer/ipv4/ControlManetRouting.msg</tt> by opp_msgc.
 * <pre>
 * packet ControlManetRouting
 * {
 *     IPAddress srcAddress;
 *     IPAddress destAddress;
 *     int optionCode enum(ManetControlType) = MANET_ROUTE_NO_OPTION;
 * }
 * </pre>
 */
class ControlManetRouting : public ::cPacket
{
  protected:
    ::IPAddress srcAddress_var;
    ::IPAddress destAddress_var;
    int optionCode_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ControlManetRouting&);

  public:
    ControlManetRouting(const char *name=NULL, int kind=0);
    ControlManetRouting(const ControlManetRouting& other);
    virtual ~ControlManetRouting();
    ControlManetRouting& operator=(const ControlManetRouting& other);
    virtual ControlManetRouting *dup() const {return new ControlManetRouting(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual IPAddress& getSrcAddress();
    virtual const IPAddress& getSrcAddress() const {return const_cast<ControlManetRouting*>(this)->getSrcAddress();}
    virtual void setSrcAddress(const IPAddress& srcAddress_var);
    virtual IPAddress& getDestAddress();
    virtual const IPAddress& getDestAddress() const {return const_cast<ControlManetRouting*>(this)->getDestAddress();}
    virtual void setDestAddress(const IPAddress& destAddress_var);
    virtual int getOptionCode() const;
    virtual void setOptionCode(int optionCode_var);
};

inline void doPacking(cCommBuffer *b, ControlManetRouting& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, ControlManetRouting& obj) {obj.parsimUnpack(b);}


#endif // _CONTROLMANETROUTING_M_H_
