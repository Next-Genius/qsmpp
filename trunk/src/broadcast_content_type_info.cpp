#include <broadcast_content_type_info.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BroadcastContentTypeInfo::BroadcastContentTypeInfo(const octetString &value):
  TLV(constants::TLVtags::BROADCAST_CONTENT_TYPE_INFO, value.size()),
  value(value) {

}

BroadcastContentTypeInfo::BroadcastContentTypeInfo(
  const BroadcastContentTypeInfo &other):
    TLV(other), value(other.getValue()) {

}

bool BroadcastContentTypeInfo::operator ==(
  const BroadcastContentTypeInfo &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool BroadcastContentTypeInfo::operator !=(
  const BroadcastContentTypeInfo &other) const {
  return !this->operator ==(other);
}

BroadcastContentTypeInfo &BroadcastContentTypeInfo::operator =(
  const BroadcastContentTypeInfo &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void BroadcastContentTypeInfo::setValue(const octetString &value) {
  this->value = value;
}

octetString BroadcastContentTypeInfo::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
