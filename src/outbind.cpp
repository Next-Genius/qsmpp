#include <outbind.h>

namespace qsmpp {
namespace pdu {

Outbind::Outbind(const Header &other_header,
                 const CoctetString &system_id,
                 const CoctetString &password):
  Header(other_header),
  system_id(system_id),
  password(password) {

}

Outbind::Outbind(const Outbind &other):
  Header(other),
  system_id(other.getSystemId()),
  password(other.getPassword()) {

}

bool Outbind::operator ==(const Outbind &other) const {
  return (Header::operator ==(other) &&
          system_id == other.getSystemId() &&
          password == other.getPassword());
}

bool Outbind::operator !=(const Outbind &other) const {
  return !this->operator ==(other);
}

Outbind &Outbind::operator =(const Outbind &other) {
  if (*this == other)
    return *this;
  Header::operator =(other);
  system_id = other.getSystemId();
  password = other.getPassword();
  return *this;
}

void Outbind::setSystemId(const CoctetString &system_id) {
  this->system_id = system_id;
}

CoctetString Outbind::getSystemId() const {
  return system_id;
}

void Outbind::setPassword(const CoctetString &password) {
  this->password = password;
}

CoctetString Outbind::getPassword() const {
  return password;
}

} // namespace pdu
} // namespace qsmpp
