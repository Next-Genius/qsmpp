#include <dest_network_id.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DestNetworkId::DestNetworkId(const CoctetString &value):
  TLV(constants::TLVtags::DEST_NETWORK_ID, value.size() + 1), value(value) {

}

DestNetworkId::DestNetworkId(const DestNetworkId &other):
  TLV(other), value(other.getValue()) {

}

bool DestNetworkId::operator ==(const DestNetworkId &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DestNetworkId::operator !=(const DestNetworkId &other) const {
  return !this->operator ==(other);
}

DestNetworkId &DestNetworkId::operator =(const DestNetworkId &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DestNetworkId::setValue(const CoctetString &value) {
  this->value = value;
}

CoctetString DestNetworkId::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
