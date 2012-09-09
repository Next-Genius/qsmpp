#include <broadcast_content_type.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BroadcastContentType::BroadcastContentType(
  const octetString &value):
    TLV(constants::TLVtags::BROADCAST_CONTENT_TYPE, value.size()),
    value(value) {

}

BroadcastContentType::BroadcastContentType(
  const BroadcastContentType &other):
    TLV(other),
    value(other.getValue()) {

}

bool BroadcastContentType::operator ==(
  const BroadcastContentType &other) const {
  return (TLV::operator ==(other) &&
          value == other.getValue());
}

bool BroadcastContentType::operator !=(
  const BroadcastContentType &other) const {
  return !this->operator ==(other);
}

BroadcastContentType &BroadcastContentType::operator =(
  const BroadcastContentType &other) {
  if(*this == other)
    return *this;
  TLV::operator = (other);
  value = other.getValue();
  return *this;
}

void BroadcastContentType::setValue(const octetString &value) {
  this->value = value;
}

octetString BroadcastContentType::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
