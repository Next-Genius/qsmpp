#ifndef SMPP_STANDART_PARAMETERS_H
#define SMPP_STANDART_PARAMETERS_H

#include <types.h>
#include <list>

namespace smpp {

class SystemId : public CString {
public:
  enum { MaxLength = 16 };
  SystemId &operator =(const char *p) {
    CString::operator =(p);
    return *this;
  }
};

class Password : public CString {
public:
  enum { MaxLength = 9 };
  Password &operator =(const char *p) {
    CString::operator =(p);
    return *this;
  }
};

class SystemType : public CString {
public:
  enum { MaxLength = 13 };
  SystemType &operator =(const char *p) {
    CString::operator =(p);
    return *this;
  }
};

class InterfaceVersion {
  uint8 value;
public:
  enum {
    V33 = 0x33, // Version 3.3
    V34 = 0x34, // Version 3.4
    V50 = 0x50  // Version 5.0
  };

  InterfaceVersion() : value(V50) {}
  explicit InterfaceVersion(const uint8 &p) : value(p) {}
  explicit InterfaceVersion(int p) : value(p) {}
  InterfaceVersion &operator=(const uint8 &p) {
    value = p; return *this;
  }
  InterfaceVersion &operator=(const int &p) {
    value = p; return *this;
  }
  operator uint8() const { return value; }
};

class AddressRange : public CString {
public:
  enum { MaxLength = 41 };
  AddressRange &operator =(const char *p) {
    CString::operator =(p);
    return *this;
  }
};

class ServiceType : public CString {
public:
  enum { MaxLength = 6 };
  ServiceType &operator =(const char *p) {
    CString::operator =(p);
    return *this;
  }
};

class Ton {
  uint8 value;
public:
  enum {
    Unknown       = 0x00, // Unknown (default)
    International = 0x01, // International
    National      = 0x02, // National
    Network       = 0x03, // Network
    Subscriber    = 0x04, // Subscriber
    Alphanumeric  = 0x05, // Alphanumeric
    Abbreviated   = 0x06  // Abbreviated
  };

  Ton() : value(Unknown) {}
  explicit Ton(const uint8 &p) : value(p) {}
  explicit Ton(int p) : value(p) {}
  Ton &operator =(const uint8 &p) { value =  p; return *this; }
  Ton &operator =(const int &p) { value = p; return *this; }
  operator uint8() const { return value; }
};

class Npi {
  uint8 value;
public:
  enum {
    Unknown  = 0x00, // Unknown
    E164     = 0x01, // E164
    Data     = 0x03, // Data
    Telex    = 0x04, // Telex
    Mobile   = 0x06, // Mobile
    National = 0x08, // National
    Private  = 0x09, // Private
    Ermes    = 0x0a, // ERMES
    Internet = 0x0e, // Internet
    Wap      = 0x12  // WAP
  };

  Npi() : value(Unknown) {}
  explicit Npi(const uint8 &p) : value(p) {}
  Npi &operator =(const uint8 &p) { value = p; return *this; }
  operator uint8() const { return value; }
};

class Address : public CString {
public:
  enum {
    MaxLen = 21,      // Normal address length
    MaxDataSmLen = 65 // Extended address lenth - data_sm
  };
  Address &operator =(const char *p) {
    CString::operator =(p);
    return *this;
  }
};

class SmeAddress {
  Ton ton;
  Npi npi;
  Address addr;
public:
  SmeAddress() {}

  SmeAddress(const Ton &ton,
             const Npi &npi,
             const Address &addr) :
    ton(ton), npi(npi), addr(addr) {}

  explicit SmeAddress(const Address &addr) :
    addr(addr) {}

  const Ton &getTon() const { return ton; }

  const Npi &getNpi() const { return npi; }

  const Address &getAddress() const { return addr; }

  size_t length() const { return 2 + addr.length() + 1; }
};

class MultiDestinationAddressBase {
public:
  virtual ~MultiDestinationAddressBase() {}
  virtual uint8 Type() const = 0;
};

class SmeMultiAddress : public MultiDestinationAddressBase {
  SmeAddress addr;
public:
  SmeMultiAddress(const SmeAddress &addr) : addr(addr) {}
  virtual uint8 Type() const { return 0x01; }
  const SmeAddress &Value() const { return addr; }
};

class DistributionListAddress : public MultiDestinationAddressBase {
  CString addr;
public:
  DistributionListAddress(const CString &addr) : addr(addr) {}
  virtual uint8 Type() const { return 0x02; }
  const CString &Value() const { return addr; }
};

class MultiDestinationAddresses {
  typedef std::list<MultiDestinationAddressBase *> List;
  List addrs;
  int len;
  struct Delete {
    void operator() (const MultiDestinationAddressBase *p) {
      delete p;
    }
  };
public:
  MultiDestinationAddresses() : len(0) {}

  ~MultiDestinationAddresses() throw() {
    std::for_each(addrs.begin(), addrs.end(), Delete());
  }

  uint32 add(const SmeAddress &p) {
    if(addrs.size() < 255) {
      MultiDestinationAddressBase *t = new SmeMultiAddress(p);
      addrs.push_back(t);
      int l(p.length() + 1);
      len += l;
      return l;
    }
    return 0;
  }

  uint32 add(const CString &p) {
    if(addrs.size() < 255) {
      MultiDestinationAddressBase *t = new DistributionListAddress(p);
      addrs.push_back(t);
      int l(p.length() + 2);
      len += l;
      return l;
    }
    return 0;
  }

  uint8 size() const { return addrs.size(); }

  int length() const { return len; }

  const List &getList() const { return addrs; }
};

class UnsuccessSme {
  SmeAddress sme_sddress;
  uint32 error;
public:
  UnsuccessSme() : error(0) {}

  UnsuccessSme(const SmeAddress &p, const uint32 &error) :
    sme_sddress(p), error(error) {}

  UnsuccessSme(const UnsuccessSme &p) :
    sme_sddress(p.sme_sddress), error(p.error) {}

  void setSmeAddress(const SmeAddress &p) { sme_sddress = p; }

  void setError(const uint32 &p) { error = p; }

  const SmeAddress &getSmeAddress() const { return sme_sddress; }

  const uint32 &getError() const { return error; }

  uint32 length() const {
    return sme_sddress.length() + 4;
  }
};

class UnsuccessSmeColl {
public:
  typedef std::list<UnsuccessSme *> List;
private:
  List value;

  struct Delete {
    void operator()(const UnsuccessSme *p) { delete p; }
  };
public:
  UnsuccessSmeColl() {}

  ~UnsuccessSmeColl() throw() {
    std::for_each(value.begin(), value.end(), Delete());
  }

  uint32 add(const UnsuccessSme &p) {
    if(value.size() < 255) {
      UnsuccessSme *ptr = new UnsuccessSme(p);
      value.push_back(ptr);
      return p.length();
    }
    return 0;
  }

  uint8 size() const { return value.size(); }

  const List &getList() const { return value; }
};

class EsmClass {
  uint8 value;
public:
  explicit EsmClass(const uint8 &p = 0x00) : value(p) {}
  EsmClass &operator =(const uint8 &p) { value = p; return *this; }
  operator uint8() const { return value; }
};

class ProtocolId {
  uint8 value;
public:
  explicit ProtocolId(const uint8 &p = 0x00) : value(p) {}
  ProtocolId &operator =(const uint8 &p) { value = p;  return *this; }
  operator uint8() const { return value; }
};

class PriorityFlag {
  uint8 value;
public:
  enum {
    Normal     = 0x00,
    Immediate  = 0x01,
    High       = 0x02,
    Reserved   = 0x03, // very urgent, emergency
    Background = 0x04
  };

  PriorityFlag() : value(Normal) {}
  explicit PriorityFlag(const uint8 &p) : value(p) {}
  PriorityFlag &operator =(const uint8 &p) { value = p; return *this; }
  operator uint8() const { return value; }
};

class Time : public CString {
public:
  enum { MaxLength = 17 };
  Time &operator =(const char *p) {
    CString::operator =(p);
    return *this;
  }
};

class RegisteredDelivery {
  uint8 value;
public:
  enum { Default = 0x00 };

  RegisteredDelivery() : value(Default) {}
  RegisteredDelivery(const uint8 &p) : value(p) {}
  RegisteredDelivery &operator =(const uint8 &p) {
    value = p; return *this;
  }
  operator uint8() const { return value; }
};

class ReplaceIfPresentFlag {
  uint8 value;
public:
  enum { NoReplace = 0x00, Replace = 0x01 };

  ReplaceIfPresentFlag() : value(NoReplace) {}
  ReplaceIfPresentFlag(const uint8 &p) : value(p) {}
  ReplaceIfPresentFlag &operator =(const uint8 &p) {
      value = p; return *this;
  }
  operator uint8() const { return value; }
};

class DataCoding {
  uint8 value;
public:
  DataCoding() : value(0x00) {}
  DataCoding(const uint8 &p) : value(p) {}
  DataCoding &operator =(const uint8 &p) {
    value = p; return *this;
  }
  operator uint8() const { return value; }
};

class SmDefaultMsgId {
  uint8 value;
public:
  enum { Unused = 0x00 };

  SmDefaultMsgId() : value(Unused) {}
  SmDefaultMsgId(const uint8 &p) : value(p) {}
  SmDefaultMsgId &operator =(const uint8 &p) {
    value = p; return *this;
  }
  operator uint8() const { return value; }
};

class ShortMessage {
  String value;
public:
  enum { MaxLength = 255 };

  ShortMessage() { value.reserve(MaxLength); }

  ShortMessage(const uint8 *p, uint8 len) : value(p, p + len) {}

  explicit ShortMessage(const char *p) : value(p, p + strlen(p)) {}

  explicit ShortMessage(const CString &p) : value(p.begin(), p.end()) {}

  ShortMessage &operator =(const uint8 *p) {
    value.assign(p + 1, p + (*p + 1));
    return *this;
  }

  ShortMessage &operator =(const char *p) {
    value.assign(p, p + strlen(p));
    return *this;
  }

  ShortMessage &operator =(const CString &p) {
    value.assign(p.begin(), p.end());
    return *this;
  }

  operator const String&() const { return value; }

  size_t length() const { return value.size(); }

  String::const_iterator begin() const {
    return value.begin();
  }

  String::const_iterator end() const {
    return value.end();
  }
};

class MessageId : public CString {
public:
  enum { MaxLength = 65 };
  MessageId &operator =(const char *p) {
    CString::operator =(p);
    return *this;
  }
};

class MessageState {
  uint8 value;
public:
  enum {
    SCHEDULED = 0,
    ENROUTE = 1,
    DELIVERED = 2,
    EXPIRED = 3,
    DELETED = 4,
    UNDELIVERABLE = 5,
    ACCEPTED = 6,
    UNKNOWN = 7,
    REJECTED = 8,
    SKIPPED = 9
  };

  MessageState() : value(0x00) {}
  MessageState(const uint8 &p) : value(p) {}
  MessageState &operator =(const uint8 &p) {
    value = p; return *this;
  }
  operator uint8() const { return value; }
};

class ErrorCode {
  uint8 value;
public:
  ErrorCode() : value(0x00) {}
  ErrorCode(const uint8 &p) : value(p) {}
  ErrorCode &operator =(const uint8 &p) {
    value = p; return *this;
  }
  operator uint8() const { return value; }
};

} // namespace smpp

#endif // SMPP_STANDART_PARAMETERS_H
