#include <user_response_code.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

UserResponseCode::UserResponseCode(quint8 value):
  TLV(constants::TLVtags::USER_RESPONSE_CODE, 1), value(value) {

}

UserResponseCode::UserResponseCode(const UserResponseCode &other):
  TLV(other), value(other.getValue()) {

}

bool UserResponseCode::operator ==(const UserResponseCode &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool UserResponseCode::operator !=(const UserResponseCode &other) const {
  return !this->operator ==(other);
}

UserResponseCode &UserResponseCode::operator =(
  const UserResponseCode &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void UserResponseCode::setValue(quint8 value) {
  this->value = value;
}

quint8 UserResponseCode::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
