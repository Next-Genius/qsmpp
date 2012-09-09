#include <bind.h>

namespace qsmpp {
namespace pdu {

Bind::Bind(const Header &other_header,
           const CoctetString &system_id,
           const CoctetString &password,
           const CoctetString &system_type,
           quint8 interface_version,
           quint8 addr_ton,
           quint8 addr_npi,
           const CoctetString &address_range):
  Header(other_header),
  system_id(system_id),
  password(password),
  system_type(system_type),
  interface_version(interface_version),
  addr_ton(addr_ton),
  addr_npi(addr_npi),
  address_range(address_range) {

}

Bind::Bind(const Bind &other):
  Header(other),
  system_id(other.getSystemId()),
  password(other.getPassword()),
  system_type(other.getSystemType()),
  interface_version(other.getInterfaceVersion()),
  addr_ton(other.getAddrTON()),
  addr_npi(other.getAddrNPI()),
  address_range(other.getAddressRange()) {

}

bool Bind::operator ==(const Bind &other) const {
  return (Header::operator ==(other) &&
          system_id == other.getSystemId() &&
          password == other.getPassword() &&
          system_type == other.getSystemType() &&
          interface_version == other.getInterfaceVersion() &&
          addr_ton == other.getAddrTON() &&
          addr_npi == other.getAddrNPI() &&
          address_range == other.getAddressRange());
}

bool Bind::operator !=(const Bind &other) const {
  return !this->operator ==(other);
}

Bind &Bind::operator =(const Bind &other) {
  if (*this == other)
    return *this;
  Header::operator =(other);
  system_id = other.getSystemId();
  password = other.getPassword();
  system_type = other.getSystemType();
  interface_version = other.getInterfaceVersion();
  addr_ton = other.getAddrTON();
  addr_npi = other.getAddrNPI();
  address_range = other.getAddressRange();
  return *this;
}

void Bind::setSystemId(const CoctetString &system_id) {
  this->system_id = system_id;
}

CoctetString Bind::getSystemId() const {
  return system_id;
}

void Bind::setPassword(const CoctetString &password) {
  this->password = password;
}

CoctetString Bind::getPassword() const {
  return password;
}

void Bind::setSystemType(const CoctetString &system_type) {
  this->system_type = system_type;
}

CoctetString Bind::getSystemType() const{
  return system_type;
}

void Bind::setInterfaceVersion(quint8 interface_version) {
  this->interface_version = interface_version;
}

quint8 Bind::getInterfaceVersion() const {
  return interface_version;
}

void Bind::setAddrTON(quint8 addr_ton) {
  this->addr_ton = addr_ton;
}

quint8 Bind::getAddrTON() const {
  return addr_ton;
}

void Bind::setAddrNPI(quint8 addr_npi) {
  this->addr_npi = addr_npi;
}

quint8 Bind::getAddrNPI() const {
  return addr_npi;
}

void Bind::setAddressRange(const CoctetString &address_range) {
  this->address_range = address_range;
}

CoctetString Bind::getAddressRange() const {
  return address_range;
}

} // namespace pdu
} // namespace qsmpp
