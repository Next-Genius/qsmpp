#include <dest_network_type.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DestNetworkType::DestNetworkType(quint8 value):
  TLV(constants::TLVtags::DEST_NETWORK_TYPE, 1), value(value) {

}

DestNetworkType::DestNetworkType(const DestNetworkType &other):
  TLV(other), value(other.getValue()) {

}

bool DestNetworkType::operator ==(const DestNetworkType &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DestNetworkType::operator !=(const DestNetworkType &other) const {
  return !this->operator ==(other);
}

DestNetworkType &DestNetworkType::operator =(const DestNetworkType &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DestNetworkType::setValue(quint8 value) {
  this->value = value;
}

quint8 DestNetworkType::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
