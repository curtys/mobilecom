//
// Generated file, do not edit! Created by opp_msgc 4.1 from hip/HipMessages.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "HipMessages_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("HipPacketType");
    if (!e) enums.getInstance()->add(e = new cEnum("HipPacketType"));
    e->insert(I1, "I1");
    e->insert(R1, "R1");
    e->insert(I2, "I2");
    e->insert(R2, "R2");
    e->insert(UPDATE, "UPDATE");
    e->insert(NOTIFY, "NOTIFY");
    e->insert(CLOSE, "CLOSE");
    e->insert(CLOSE_ACK, "CLOSE_ACK");
    e->insert(ESP_DATA, "ESP_DATA");
    e->insert(UPDATE_SEQ, "UPDATE_SEQ");
    e->insert(UPDATE_ACK, "UPDATE_ACK");
);

HipLocator::HipLocator()
{
    type = 193;
    length = 0;
    trafficType = 0;
    locatorType = 1;
    locatorLength = 0;
    reserved = 0;
    p = 0;
    locatorLifetime = 0;
    locatorESP_SPI = 0;
}

void doPacking(cCommBuffer *b, HipLocator& a)
{
    doPacking(b,a.type);
    doPacking(b,a.length);
    doPacking(b,a.trafficType);
    doPacking(b,a.locatorType);
    doPacking(b,a.locatorLength);
    doPacking(b,a.reserved);
    doPacking(b,a.p);
    doPacking(b,a.locatorLifetime);
    doPacking(b,a.locatorIPv6addr);
    doPacking(b,a.locatorESP_SPI);
}

void doUnpacking(cCommBuffer *b, HipLocator& a)
{
    doUnpacking(b,a.type);
    doUnpacking(b,a.length);
    doUnpacking(b,a.trafficType);
    doUnpacking(b,a.locatorType);
    doUnpacking(b,a.locatorLength);
    doUnpacking(b,a.reserved);
    doUnpacking(b,a.p);
    doUnpacking(b,a.locatorLifetime);
    doUnpacking(b,a.locatorIPv6addr);
    doUnpacking(b,a.locatorESP_SPI);
}

class HipLocatorDescriptor : public cClassDescriptor
{
  public:
    HipLocatorDescriptor();
    virtual ~HipLocatorDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(HipLocatorDescriptor);

HipLocatorDescriptor::HipLocatorDescriptor() : cClassDescriptor("HipLocator", "")
{
}

HipLocatorDescriptor::~HipLocatorDescriptor()
{
}

bool HipLocatorDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<HipLocator *>(obj)!=NULL;
}

const char *HipLocatorDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int HipLocatorDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount(object) : 10;
}

unsigned int HipLocatorDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *HipLocatorDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "length",
        "trafficType",
        "locatorType",
        "locatorLength",
        "reserved",
        "p",
        "locatorLifetime",
        "locatorIPv6addr",
        "locatorESP_SPI",
    };
    return (field>=0 && field<10) ? fieldNames[field] : NULL;
}

int HipLocatorDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "trafficType")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "locatorType")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "locatorLength")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "p")==0) return base+6;
    if (fieldName[0]=='l' && strcmp(fieldName, "locatorLifetime")==0) return base+7;
    if (fieldName[0]=='l' && strcmp(fieldName, "locatorIPv6addr")==0) return base+8;
    if (fieldName[0]=='l' && strcmp(fieldName, "locatorESP_SPI")==0) return base+9;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *HipLocatorDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "short",
        "short",
        "int",
        "short",
        "short",
        "int",
        "IPv6Address",
        "int",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : NULL;
}

const char *HipLocatorDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int HipLocatorDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    HipLocator *pp = (HipLocator *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string HipLocatorDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    HipLocator *pp = (HipLocator *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->type);
        case 1: return long2string(pp->length);
        case 2: return long2string(pp->trafficType);
        case 3: return long2string(pp->locatorType);
        case 4: return long2string(pp->locatorLength);
        case 5: return long2string(pp->reserved);
        case 6: return long2string(pp->p);
        case 7: return long2string(pp->locatorLifetime);
        case 8: {std::stringstream out; out << pp->locatorIPv6addr; return out.str();}
        case 9: return long2string(pp->locatorESP_SPI);
        default: return "";
    }
}

bool HipLocatorDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    HipLocator *pp = (HipLocator *)object; (void)pp;
    switch (field) {
        case 0: pp->type = string2long(value); return true;
        case 1: pp->length = string2long(value); return true;
        case 2: pp->trafficType = string2long(value); return true;
        case 3: pp->locatorType = string2long(value); return true;
        case 4: pp->locatorLength = string2long(value); return true;
        case 5: pp->reserved = string2long(value); return true;
        case 6: pp->p = string2long(value); return true;
        case 7: pp->locatorLifetime = string2long(value); return true;
        case 9: pp->locatorESP_SPI = string2long(value); return true;
        default: return false;
    }
}

const char *HipLocatorDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        "IPv6Address",
        NULL,
    };
    return (field>=0 && field<10) ? fieldStructNames[field] : NULL;
}

void *HipLocatorDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    HipLocator *pp = (HipLocator *)object; (void)pp;
    switch (field) {
        case 8: return (void *)(&pp->locatorIPv6addr); break;
        default: return NULL;
    }
}

Register_Class(HIPHeaderMessage);

HIPHeaderMessage::HIPHeaderMessage(const char *name, int kind) : cPacket(name,kind)
{
    this->nextHeader_var = IPPROTO_NONE;
    this->length_var = 4;
    this->packetType_var = 0;
    this->version_var = 1;
    this->reg_info_var = 0;
    this->reg_req_var = 0;
    this->reg_res_var = 0;
    this->rvs_mac_var = 0;
    locator_arraysize = 0;
    this->locator_var = 0;
    this->r1_counter_var = 0;
    this->puzzle_var = 0;
    this->soution_var = 0;
    this->seq_var = 0;
    this->ack_var = 0;
    this->diffie_hellman_var = 0;
    this->hip_transform_var = 0;
    this->encrypted_var = 0;
    this->host_id_var = 0;
    this->cert_var = 0;
    this->notification_var = 0;
    this->echo_request_signed_var = 0;
    this->echo_response_signed_var = 0;
    this->hmac_var = 0;
    this->hmac_2_var = 0;
    this->hip_signature_var = 0;
    this->echo_request_unsigned_var = 0;
    this->echo_response_unsigned_var = 0;
}

HIPHeaderMessage::HIPHeaderMessage(const HIPHeaderMessage& other) : cPacket()
{
    setName(other.getName());
    locator_arraysize = 0;
    this->locator_var = 0;
    operator=(other);
}

HIPHeaderMessage::~HIPHeaderMessage()
{
    delete [] locator_var;
}

HIPHeaderMessage& HIPHeaderMessage::operator=(const HIPHeaderMessage& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->nextHeader_var = other.nextHeader_var;
    this->length_var = other.length_var;
    this->packetType_var = other.packetType_var;
    this->version_var = other.version_var;
    this->srcHIT_var = other.srcHIT_var;
    this->destHIT_var = other.destHIT_var;
    this->reg_info_var = other.reg_info_var;
    this->reg_req_var = other.reg_req_var;
    this->reg_res_var = other.reg_res_var;
    this->from_i_var = other.from_i_var;
    this->rvs_mac_var = other.rvs_mac_var;
    this->via_rvs_var = other.via_rvs_var;
    delete [] this->locator_var;
    this->locator_var = (other.locator_arraysize==0) ? NULL : new ::HipLocator[other.locator_arraysize];
    locator_arraysize = other.locator_arraysize;
    for (unsigned int i=0; i<locator_arraysize; i++)
        this->locator_var[i] = other.locator_var[i];
    this->r1_counter_var = other.r1_counter_var;
    this->puzzle_var = other.puzzle_var;
    this->soution_var = other.soution_var;
    this->seq_var = other.seq_var;
    this->ack_var = other.ack_var;
    this->diffie_hellman_var = other.diffie_hellman_var;
    this->hip_transform_var = other.hip_transform_var;
    this->encrypted_var = other.encrypted_var;
    this->host_id_var = other.host_id_var;
    this->cert_var = other.cert_var;
    this->notification_var = other.notification_var;
    this->echo_request_signed_var = other.echo_request_signed_var;
    this->echo_response_signed_var = other.echo_response_signed_var;
    this->hmac_var = other.hmac_var;
    this->hmac_2_var = other.hmac_2_var;
    this->hip_signature_var = other.hip_signature_var;
    this->echo_request_unsigned_var = other.echo_request_unsigned_var;
    this->echo_response_unsigned_var = other.echo_response_unsigned_var;
    return *this;
}

void HIPHeaderMessage::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->nextHeader_var);
    doPacking(b,this->length_var);
    doPacking(b,this->packetType_var);
    doPacking(b,this->version_var);
    doPacking(b,this->srcHIT_var);
    doPacking(b,this->destHIT_var);
    doPacking(b,this->reg_info_var);
    doPacking(b,this->reg_req_var);
    doPacking(b,this->reg_res_var);
    doPacking(b,this->from_i_var);
    doPacking(b,this->rvs_mac_var);
    doPacking(b,this->via_rvs_var);
    b->pack(locator_arraysize);
    doPacking(b,this->locator_var,locator_arraysize);
    doPacking(b,this->r1_counter_var);
    doPacking(b,this->puzzle_var);
    doPacking(b,this->soution_var);
    doPacking(b,this->seq_var);
    doPacking(b,this->ack_var);
    doPacking(b,this->diffie_hellman_var);
    doPacking(b,this->hip_transform_var);
    doPacking(b,this->encrypted_var);
    doPacking(b,this->host_id_var);
    doPacking(b,this->cert_var);
    doPacking(b,this->notification_var);
    doPacking(b,this->echo_request_signed_var);
    doPacking(b,this->echo_response_signed_var);
    doPacking(b,this->hmac_var);
    doPacking(b,this->hmac_2_var);
    doPacking(b,this->hip_signature_var);
    doPacking(b,this->echo_request_unsigned_var);
    doPacking(b,this->echo_response_unsigned_var);
}

void HIPHeaderMessage::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->nextHeader_var);
    doUnpacking(b,this->length_var);
    doUnpacking(b,this->packetType_var);
    doUnpacking(b,this->version_var);
    doUnpacking(b,this->srcHIT_var);
    doUnpacking(b,this->destHIT_var);
    doUnpacking(b,this->reg_info_var);
    doUnpacking(b,this->reg_req_var);
    doUnpacking(b,this->reg_res_var);
    doUnpacking(b,this->from_i_var);
    doUnpacking(b,this->rvs_mac_var);
    doUnpacking(b,this->via_rvs_var);
    delete [] this->locator_var;
    b->unpack(locator_arraysize);
    if (locator_arraysize==0) {
        this->locator_var = 0;
    } else {
        this->locator_var = new ::HipLocator[locator_arraysize];
        doUnpacking(b,this->locator_var,locator_arraysize);
    }
    doUnpacking(b,this->r1_counter_var);
    doUnpacking(b,this->puzzle_var);
    doUnpacking(b,this->soution_var);
    doUnpacking(b,this->seq_var);
    doUnpacking(b,this->ack_var);
    doUnpacking(b,this->diffie_hellman_var);
    doUnpacking(b,this->hip_transform_var);
    doUnpacking(b,this->encrypted_var);
    doUnpacking(b,this->host_id_var);
    doUnpacking(b,this->cert_var);
    doUnpacking(b,this->notification_var);
    doUnpacking(b,this->echo_request_signed_var);
    doUnpacking(b,this->echo_response_signed_var);
    doUnpacking(b,this->hmac_var);
    doUnpacking(b,this->hmac_2_var);
    doUnpacking(b,this->hip_signature_var);
    doUnpacking(b,this->echo_request_unsigned_var);
    doUnpacking(b,this->echo_response_unsigned_var);
}

int HIPHeaderMessage::getNextHeader() const
{
    return nextHeader_var;
}

void HIPHeaderMessage::setNextHeader(int nextHeader_var)
{
    this->nextHeader_var = nextHeader_var;
}

int HIPHeaderMessage::getLength() const
{
    return length_var;
}

void HIPHeaderMessage::setLength(int length_var)
{
    this->length_var = length_var;
}

int HIPHeaderMessage::getPacketType() const
{
    return packetType_var;
}

void HIPHeaderMessage::setPacketType(int packetType_var)
{
    this->packetType_var = packetType_var;
}

short HIPHeaderMessage::getVersion() const
{
    return version_var;
}

void HIPHeaderMessage::setVersion(short version_var)
{
    this->version_var = version_var;
}

IPv6Address& HIPHeaderMessage::getSrcHIT()
{
    return srcHIT_var;
}

void HIPHeaderMessage::setSrcHIT(const IPv6Address& srcHIT_var)
{
    this->srcHIT_var = srcHIT_var;
}

IPv6Address& HIPHeaderMessage::getDestHIT()
{
    return destHIT_var;
}

void HIPHeaderMessage::setDestHIT(const IPv6Address& destHIT_var)
{
    this->destHIT_var = destHIT_var;
}

short HIPHeaderMessage::getReg_info() const
{
    return reg_info_var;
}

void HIPHeaderMessage::setReg_info(short reg_info_var)
{
    this->reg_info_var = reg_info_var;
}

short HIPHeaderMessage::getReg_req() const
{
    return reg_req_var;
}

void HIPHeaderMessage::setReg_req(short reg_req_var)
{
    this->reg_req_var = reg_req_var;
}

short HIPHeaderMessage::getReg_res() const
{
    return reg_res_var;
}

void HIPHeaderMessage::setReg_res(short reg_res_var)
{
    this->reg_res_var = reg_res_var;
}

IPv6Address& HIPHeaderMessage::getFrom_i()
{
    return from_i_var;
}

void HIPHeaderMessage::setFrom_i(const IPv6Address& from_i_var)
{
    this->from_i_var = from_i_var;
}

int HIPHeaderMessage::getRvs_mac() const
{
    return rvs_mac_var;
}

void HIPHeaderMessage::setRvs_mac(int rvs_mac_var)
{
    this->rvs_mac_var = rvs_mac_var;
}

IPv6Address& HIPHeaderMessage::getVia_rvs()
{
    return via_rvs_var;
}

void HIPHeaderMessage::setVia_rvs(const IPv6Address& via_rvs_var)
{
    this->via_rvs_var = via_rvs_var;
}

void HIPHeaderMessage::setLocatorArraySize(unsigned int size)
{
    ::HipLocator *locator_var2 = (size==0) ? NULL : new ::HipLocator[size];
    unsigned int sz = locator_arraysize < size ? locator_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        locator_var2[i] = this->locator_var[i];
    locator_arraysize = size;
    delete [] this->locator_var;
    this->locator_var = locator_var2;
}

unsigned int HIPHeaderMessage::getLocatorArraySize() const
{
    return locator_arraysize;
}

HipLocator& HIPHeaderMessage::getLocator(unsigned int k)
{
    if (k>=locator_arraysize) throw cRuntimeError("Array of size %d indexed by %d", locator_arraysize, k);
    return locator_var[k];
}

void HIPHeaderMessage::setLocator(unsigned int k, const HipLocator& locator_var)
{
    if (k>=locator_arraysize) throw cRuntimeError("Array of size %d indexed by %d", locator_arraysize, k);
    this->locator_var[k]=locator_var;
}

unsigned int HIPHeaderMessage::getR1_counter() const
{
    return r1_counter_var;
}

void HIPHeaderMessage::setR1_counter(unsigned int r1_counter_var)
{
    this->r1_counter_var = r1_counter_var;
}

int HIPHeaderMessage::getPuzzle() const
{
    return puzzle_var;
}

void HIPHeaderMessage::setPuzzle(int puzzle_var)
{
    this->puzzle_var = puzzle_var;
}

int HIPHeaderMessage::getSoution() const
{
    return soution_var;
}

void HIPHeaderMessage::setSoution(int soution_var)
{
    this->soution_var = soution_var;
}

int HIPHeaderMessage::getSeq() const
{
    return seq_var;
}

void HIPHeaderMessage::setSeq(int seq_var)
{
    this->seq_var = seq_var;
}

int HIPHeaderMessage::getAck() const
{
    return ack_var;
}

void HIPHeaderMessage::setAck(int ack_var)
{
    this->ack_var = ack_var;
}

int HIPHeaderMessage::getDiffie_hellman() const
{
    return diffie_hellman_var;
}

void HIPHeaderMessage::setDiffie_hellman(int diffie_hellman_var)
{
    this->diffie_hellman_var = diffie_hellman_var;
}

int HIPHeaderMessage::getHip_transform() const
{
    return hip_transform_var;
}

void HIPHeaderMessage::setHip_transform(int hip_transform_var)
{
    this->hip_transform_var = hip_transform_var;
}

int HIPHeaderMessage::getEncrypted() const
{
    return encrypted_var;
}

void HIPHeaderMessage::setEncrypted(int encrypted_var)
{
    this->encrypted_var = encrypted_var;
}

int HIPHeaderMessage::getHost_id() const
{
    return host_id_var;
}

void HIPHeaderMessage::setHost_id(int host_id_var)
{
    this->host_id_var = host_id_var;
}

int HIPHeaderMessage::getCert() const
{
    return cert_var;
}

void HIPHeaderMessage::setCert(int cert_var)
{
    this->cert_var = cert_var;
}

int HIPHeaderMessage::getNotification() const
{
    return notification_var;
}

void HIPHeaderMessage::setNotification(int notification_var)
{
    this->notification_var = notification_var;
}

int HIPHeaderMessage::getEcho_request_signed() const
{
    return echo_request_signed_var;
}

void HIPHeaderMessage::setEcho_request_signed(int echo_request_signed_var)
{
    this->echo_request_signed_var = echo_request_signed_var;
}

int HIPHeaderMessage::getEcho_response_signed() const
{
    return echo_response_signed_var;
}

void HIPHeaderMessage::setEcho_response_signed(int echo_response_signed_var)
{
    this->echo_response_signed_var = echo_response_signed_var;
}

int HIPHeaderMessage::getHmac() const
{
    return hmac_var;
}

void HIPHeaderMessage::setHmac(int hmac_var)
{
    this->hmac_var = hmac_var;
}

int HIPHeaderMessage::getHmac_2() const
{
    return hmac_2_var;
}

void HIPHeaderMessage::setHmac_2(int hmac_2_var)
{
    this->hmac_2_var = hmac_2_var;
}

int HIPHeaderMessage::getHip_signature() const
{
    return hip_signature_var;
}

void HIPHeaderMessage::setHip_signature(int hip_signature_var)
{
    this->hip_signature_var = hip_signature_var;
}

int HIPHeaderMessage::getEcho_request_unsigned() const
{
    return echo_request_unsigned_var;
}

void HIPHeaderMessage::setEcho_request_unsigned(int echo_request_unsigned_var)
{
    this->echo_request_unsigned_var = echo_request_unsigned_var;
}

int HIPHeaderMessage::getEcho_response_unsigned() const
{
    return echo_response_unsigned_var;
}

void HIPHeaderMessage::setEcho_response_unsigned(int echo_response_unsigned_var)
{
    this->echo_response_unsigned_var = echo_response_unsigned_var;
}

class HIPHeaderMessageDescriptor : public cClassDescriptor
{
  public:
    HIPHeaderMessageDescriptor();
    virtual ~HIPHeaderMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(HIPHeaderMessageDescriptor);

HIPHeaderMessageDescriptor::HIPHeaderMessageDescriptor() : cClassDescriptor("HIPHeaderMessage", "cPacket")
{
}

HIPHeaderMessageDescriptor::~HIPHeaderMessageDescriptor()
{
}

bool HIPHeaderMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<HIPHeaderMessage *>(obj)!=NULL;
}

const char *HIPHeaderMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int HIPHeaderMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 31+basedesc->getFieldCount(object) : 31;
}

unsigned int HIPHeaderMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<31) ? fieldTypeFlags[field] : 0;
}

const char *HIPHeaderMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "nextHeader",
        "length",
        "packetType",
        "version",
        "srcHIT",
        "destHIT",
        "reg_info",
        "reg_req",
        "reg_res",
        "from_i",
        "rvs_mac",
        "via_rvs",
        "locator",
        "r1_counter",
        "puzzle",
        "soution",
        "seq",
        "ack",
        "diffie_hellman",
        "hip_transform",
        "encrypted",
        "host_id",
        "cert",
        "notification",
        "echo_request_signed",
        "echo_response_signed",
        "hmac",
        "hmac_2",
        "hip_signature",
        "echo_request_unsigned",
        "echo_response_unsigned",
    };
    return (field>=0 && field<31) ? fieldNames[field] : NULL;
}

int HIPHeaderMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHeader")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+2;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcHIT")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "destHIT")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "reg_info")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "reg_req")==0) return base+7;
    if (fieldName[0]=='r' && strcmp(fieldName, "reg_res")==0) return base+8;
    if (fieldName[0]=='f' && strcmp(fieldName, "from_i")==0) return base+9;
    if (fieldName[0]=='r' && strcmp(fieldName, "rvs_mac")==0) return base+10;
    if (fieldName[0]=='v' && strcmp(fieldName, "via_rvs")==0) return base+11;
    if (fieldName[0]=='l' && strcmp(fieldName, "locator")==0) return base+12;
    if (fieldName[0]=='r' && strcmp(fieldName, "r1_counter")==0) return base+13;
    if (fieldName[0]=='p' && strcmp(fieldName, "puzzle")==0) return base+14;
    if (fieldName[0]=='s' && strcmp(fieldName, "soution")==0) return base+15;
    if (fieldName[0]=='s' && strcmp(fieldName, "seq")==0) return base+16;
    if (fieldName[0]=='a' && strcmp(fieldName, "ack")==0) return base+17;
    if (fieldName[0]=='d' && strcmp(fieldName, "diffie_hellman")==0) return base+18;
    if (fieldName[0]=='h' && strcmp(fieldName, "hip_transform")==0) return base+19;
    if (fieldName[0]=='e' && strcmp(fieldName, "encrypted")==0) return base+20;
    if (fieldName[0]=='h' && strcmp(fieldName, "host_id")==0) return base+21;
    if (fieldName[0]=='c' && strcmp(fieldName, "cert")==0) return base+22;
    if (fieldName[0]=='n' && strcmp(fieldName, "notification")==0) return base+23;
    if (fieldName[0]=='e' && strcmp(fieldName, "echo_request_signed")==0) return base+24;
    if (fieldName[0]=='e' && strcmp(fieldName, "echo_response_signed")==0) return base+25;
    if (fieldName[0]=='h' && strcmp(fieldName, "hmac")==0) return base+26;
    if (fieldName[0]=='h' && strcmp(fieldName, "hmac_2")==0) return base+27;
    if (fieldName[0]=='h' && strcmp(fieldName, "hip_signature")==0) return base+28;
    if (fieldName[0]=='e' && strcmp(fieldName, "echo_request_unsigned")==0) return base+29;
    if (fieldName[0]=='e' && strcmp(fieldName, "echo_response_unsigned")==0) return base+30;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *HIPHeaderMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "short",
        "IPv6Address",
        "IPv6Address",
        "short",
        "short",
        "short",
        "IPv6Address",
        "int",
        "IPv6Address",
        "HipLocator",
        "unsigned int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<31) ? fieldTypeStrings[field] : NULL;
}

const char *HIPHeaderMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 2:
            if (!strcmp(propertyname,"enum")) return "HipPacketType";
            return NULL;
        default: return NULL;
    }
}

int HIPHeaderMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    HIPHeaderMessage *pp = (HIPHeaderMessage *)object; (void)pp;
    switch (field) {
        case 12: return pp->getLocatorArraySize();
        default: return 0;
    }
}

std::string HIPHeaderMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    HIPHeaderMessage *pp = (HIPHeaderMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getNextHeader());
        case 1: return long2string(pp->getLength());
        case 2: return long2string(pp->getPacketType());
        case 3: return long2string(pp->getVersion());
        case 4: {std::stringstream out; out << pp->getSrcHIT(); return out.str();}
        case 5: {std::stringstream out; out << pp->getDestHIT(); return out.str();}
        case 6: return long2string(pp->getReg_info());
        case 7: return long2string(pp->getReg_req());
        case 8: return long2string(pp->getReg_res());
        case 9: {std::stringstream out; out << pp->getFrom_i(); return out.str();}
        case 10: return long2string(pp->getRvs_mac());
        case 11: {std::stringstream out; out << pp->getVia_rvs(); return out.str();}
        case 12: {std::stringstream out; out << pp->getLocator(i); return out.str();}
        case 13: return ulong2string(pp->getR1_counter());
        case 14: return long2string(pp->getPuzzle());
        case 15: return long2string(pp->getSoution());
        case 16: return long2string(pp->getSeq());
        case 17: return long2string(pp->getAck());
        case 18: return long2string(pp->getDiffie_hellman());
        case 19: return long2string(pp->getHip_transform());
        case 20: return long2string(pp->getEncrypted());
        case 21: return long2string(pp->getHost_id());
        case 22: return long2string(pp->getCert());
        case 23: return long2string(pp->getNotification());
        case 24: return long2string(pp->getEcho_request_signed());
        case 25: return long2string(pp->getEcho_response_signed());
        case 26: return long2string(pp->getHmac());
        case 27: return long2string(pp->getHmac_2());
        case 28: return long2string(pp->getHip_signature());
        case 29: return long2string(pp->getEcho_request_unsigned());
        case 30: return long2string(pp->getEcho_response_unsigned());
        default: return "";
    }
}

bool HIPHeaderMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    HIPHeaderMessage *pp = (HIPHeaderMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setNextHeader(string2long(value)); return true;
        case 1: pp->setLength(string2long(value)); return true;
        case 2: pp->setPacketType(string2long(value)); return true;
        case 3: pp->setVersion(string2long(value)); return true;
        case 6: pp->setReg_info(string2long(value)); return true;
        case 7: pp->setReg_req(string2long(value)); return true;
        case 8: pp->setReg_res(string2long(value)); return true;
        case 10: pp->setRvs_mac(string2long(value)); return true;
        case 13: pp->setR1_counter(string2ulong(value)); return true;
        case 14: pp->setPuzzle(string2long(value)); return true;
        case 15: pp->setSoution(string2long(value)); return true;
        case 16: pp->setSeq(string2long(value)); return true;
        case 17: pp->setAck(string2long(value)); return true;
        case 18: pp->setDiffie_hellman(string2long(value)); return true;
        case 19: pp->setHip_transform(string2long(value)); return true;
        case 20: pp->setEncrypted(string2long(value)); return true;
        case 21: pp->setHost_id(string2long(value)); return true;
        case 22: pp->setCert(string2long(value)); return true;
        case 23: pp->setNotification(string2long(value)); return true;
        case 24: pp->setEcho_request_signed(string2long(value)); return true;
        case 25: pp->setEcho_response_signed(string2long(value)); return true;
        case 26: pp->setHmac(string2long(value)); return true;
        case 27: pp->setHmac_2(string2long(value)); return true;
        case 28: pp->setHip_signature(string2long(value)); return true;
        case 29: pp->setEcho_request_unsigned(string2long(value)); return true;
        case 30: pp->setEcho_response_unsigned(string2long(value)); return true;
        default: return false;
    }
}

const char *HIPHeaderMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        "IPv6Address",
        "IPv6Address",
        NULL,
        NULL,
        NULL,
        "IPv6Address",
        NULL,
        "IPv6Address",
        "HipLocator",
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<31) ? fieldStructNames[field] : NULL;
}

void *HIPHeaderMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    HIPHeaderMessage *pp = (HIPHeaderMessage *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getSrcHIT()); break;
        case 5: return (void *)(&pp->getDestHIT()); break;
        case 9: return (void *)(&pp->getFrom_i()); break;
        case 11: return (void *)(&pp->getVia_rvs()); break;
        case 12: return (void *)(&pp->getLocator(i)); break;
        default: return NULL;
    }
}

Register_Class(ESPMessage);

ESPMessage::ESPMessage(const char *name, int kind) : cPacket(name,kind)
{
}

ESPMessage::ESPMessage(const ESPMessage& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

ESPMessage::~ESPMessage()
{
}

ESPMessage& ESPMessage::operator=(const ESPMessage& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->esp_var = other.esp_var;
    return *this;
}

void ESPMessage::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->esp_var);
}

void ESPMessage::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->esp_var);
}

IPv6EncapsulatingSecurityPayloadHeaderPtr& ESPMessage::getEsp()
{
    return esp_var;
}

void ESPMessage::setEsp(const IPv6EncapsulatingSecurityPayloadHeaderPtr& esp_var)
{
    this->esp_var = esp_var;
}

class ESPMessageDescriptor : public cClassDescriptor
{
  public:
    ESPMessageDescriptor();
    virtual ~ESPMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ESPMessageDescriptor);

ESPMessageDescriptor::ESPMessageDescriptor() : cClassDescriptor("ESPMessage", "cPacket")
{
}

ESPMessageDescriptor::~ESPMessageDescriptor()
{
}

bool ESPMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ESPMessage *>(obj)!=NULL;
}

const char *ESPMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ESPMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int ESPMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *ESPMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "esp",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int ESPMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "esp")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ESPMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPv6EncapsulatingSecurityPayloadHeaderPtr",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *ESPMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int ESPMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ESPMessage *pp = (ESPMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ESPMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ESPMessage *pp = (ESPMessage *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getEsp(); return out.str();}
        default: return "";
    }
}

bool ESPMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ESPMessage *pp = (ESPMessage *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ESPMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IPv6EncapsulatingSecurityPayloadHeaderPtr",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *ESPMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ESPMessage *pp = (ESPMessage *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getEsp()); break;
        default: return NULL;
    }
}


