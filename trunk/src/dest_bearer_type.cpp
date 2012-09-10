#include <dest_bearer_type.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DestBearerType::DestBearerType(quint8 value):
  TLV(constants::TLVtags::DEST_BEARER_TYPE, 1), value(value) {

}

DestBearerType::DestBearerType(const DestBearerType &other):
  TLV(other), value(other.getValue()) {

}

bool DestBearerType::operator ==(const DestBearerType &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DestBearerType::operator !=(const DestBearerType &other) const {
  return !this->operator ==(other);
}

DestBearerType &DestBearerType::operator =(const DestBearerType &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DestBearerType::setValue(quint8 value) {
  this->value = value;
}

quint8 DestBearerType::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
