#include <source_bearer_type.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SourceBearerType::SourceBearerType(quint8 value):
  TLV(constants::TLVtags::SOURCE_BEARER_TYPE, 1), value(value) {

}

SourceBearerType::SourceBearerType(const SourceBearerType &other):
  TLV(other), value(other.getValue()) {

}

bool SourceBearerType::operator ==(const SourceBearerType &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SourceBearerType::operator !=(const SourceBearerType &other) const {
  return !this->operator ==(other);
}

SourceBearerType &SourceBearerType::operator =(
  const SourceBearerType &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SourceBearerType::setValue(quint8 value) {
  this->value = value;
}

quint8 SourceBearerType::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
