#ifndef QSMPP_BIND_H
#define QSMPP_BIND_H

#include <header.h>

namespace qsmpp {
namespace pdu {

class QSMPP_EXPORT Bind : public Header {
  CoctetString system_id;
  CoctetString password;
  CoctetString system_type;
  quint8 interface_version;
  quint8 addr_ton;
  quint8 addr_npi;
  CoctetString address_range;
public:
  Bind(const Header &other_header = Header(),
         const CoctetString &system_id = "",
         const CoctetString &password = "",
         const CoctetString &system_type = "",
         quint8 interface_version = constants::InterfaceVersion::SMPP_VER_5_0,
         quint8 addr_ton = 0,
         quint8 addr_npi = 0,
         const CoctetString &address_range = "");

  Bind(const Bind &other);

  bool operator ==(const Bind &other) const;

  bool operator !=(const Bind &other) const;

  Bind &operator =(const Bind &other);

  void setSystemId(const CoctetString &system_id);

  CoctetString getSystemId() const;

  void setPassword(const CoctetString &password);

  CoctetString getPassword() const;

  void setSystemType(const CoctetString &system_type);

  CoctetString getSystemType() const;

  void setInterfaceVersion(quint8 interface_version);

  quint8 getInterfaceVersion() const;

  void setAddrTON(quint8 addr_ton);

  quint8 getAddrTON() const;

  void setAddrNPI(quint8 addr_npi);

  quint8 getAddrNPI() const;

  void setAddressRange(const CoctetString &address_range);

  CoctetString getAddressRange() const;
};

} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BIND_H
