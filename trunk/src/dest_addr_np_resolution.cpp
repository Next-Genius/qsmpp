#include <dest_addr_np_resolution.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DestAddrNpResolution::DestAddrNpResolution(quint8 value):
  TLV(constants::TLVtags::DEST_ADDR_NP_RESOLUTION, 1), value(value) {

}

DestAddrNpResolution::DestAddrNpResolution(const DestAddrNpResolution &other):
  TLV(other), value(other.getValue()) {

}

bool DestAddrNpResolution::operator ==(
  const DestAddrNpResolution &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DestAddrNpResolution::operator !=(
  const DestAddrNpResolution &other) const {
  return !this->operator ==(other);
}

DestAddrNpResolution &DestAddrNpResolution::operator =(
  const DestAddrNpResolution &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DestAddrNpResolution::setValue(quint8 value) {
  this->value = value;
}

quint8 DestAddrNpResolution::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
