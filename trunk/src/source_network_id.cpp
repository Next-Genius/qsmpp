#include <source_network_id.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SourceNetworkId::SourceNetworkId(const CoctetString &value):
  TLV(constants::TLVtags::SOURCE_NETWORK_ID, value.size() + 1),
  value(value) {

}

SourceNetworkId::SourceNetworkId(const SourceNetworkId &other):
  TLV(other), value(other.getValue()) {

}

bool SourceNetworkId::operator ==(const SourceNetworkId &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SourceNetworkId::operator !=(const SourceNetworkId &other) const {
  return !this->operator ==(other);
}

SourceNetworkId &SourceNetworkId::operator =(const SourceNetworkId &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SourceNetworkId::setValue(const CoctetString &value) {
  this->value = value;
}

CoctetString SourceNetworkId::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
