#include <source_network_type.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SourceNetworkType::SourceNetworkType(quint8 value):
  TLV(constants::TLVtags::SOURCE_NETWORK_TYPE, 1), value(value) {

}

SourceNetworkType::SourceNetworkType(const SourceNetworkType &other):
  TLV(other), value(other.getValue()) {

}

bool SourceNetworkType::operator ==(const SourceNetworkType &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SourceNetworkType::operator !=(const SourceNetworkType &other) const {
  return !this->operator ==(other);
}

SourceNetworkType &SourceNetworkType::operator =(
  const SourceNetworkType &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SourceNetworkType::setValue(quint8 value) {
  this->value = value;
}

quint8 SourceNetworkType::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
