#include <sar_total_segments.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SarTotalSegments::SarTotalSegments(quint8 value):
  TLV(constants::TLVtags::SAR_TOTAL_SEGMENTS, 1), value(value) {

}

SarTotalSegments::SarTotalSegments(const SarTotalSegments &other):
  TLV(other), value(other.getValue()) {

}

bool SarTotalSegments::operator ==(const SarTotalSegments &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SarTotalSegments::operator !=(const SarTotalSegments &other) const {
  return !this->operator ==(other);
}

SarTotalSegments &SarTotalSegments::operator =(const SarTotalSegments &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SarTotalSegments::setValue(quint8 value) {
  this->value = value;
}

quint8 SarTotalSegments::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
