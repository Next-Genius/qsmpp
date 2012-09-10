#include <user_message_reference.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

UserMessageReference::UserMessageReference(quint16 value):
  TLV(constants::TLVtags::USER_MESSAGE_REFERENCE, 2), value(value) {

}

UserMessageReference::UserMessageReference(const UserMessageReference &other):
  TLV(other), value(other.getValue()) {

}

bool UserMessageReference::operator ==(
  const UserMessageReference &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool UserMessageReference::operator !=(
  const UserMessageReference &other) const {
  return !this->operator ==(other);
}

UserMessageReference &UserMessageReference::operator =(
  const UserMessageReference &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void UserMessageReference::setValue(quint16 value) {
  this->value = value;
}

quint16 UserMessageReference::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
