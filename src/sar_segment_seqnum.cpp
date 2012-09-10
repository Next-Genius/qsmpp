#include <sar_segment_seqnum.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SarSegmentSeqnum::SarSegmentSeqnum(quint8 value):
  TLV(constants::TLVtags::SAR_SEGMENT_SEQNUM, 1), value(value) {

}

SarSegmentSeqnum::SarSegmentSeqnum(const SarSegmentSeqnum &other):
  TLV(other), value(other.getValue()) {

}

bool SarSegmentSeqnum::operator ==(const SarSegmentSeqnum &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SarSegmentSeqnum::operator !=(const SarSegmentSeqnum &other) const {
  return !this->operator ==(other);
}

SarSegmentSeqnum &SarSegmentSeqnum::operator =(const SarSegmentSeqnum &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SarSegmentSeqnum::setValue(quint8 value) {
  this->value = value;
}

quint8 SarSegmentSeqnum::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
