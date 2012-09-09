#ifndef QSMPP_SAR_SEGMENT_SEQNUM_H
#define QSMPP_SAR_SEGMENT_SEQNUM_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SarSegmentSeqnum : public TLV {
  quint8 value;
public:
  SarSegmentSeqnum(quint8 value = 0);

  SarSegmentSeqnum(const SarSegmentSeqnum &other);

  bool operator ==(const SarSegmentSeqnum &other) const;

  bool operator !=(const SarSegmentSeqnum &other) const;

  SarSegmentSeqnum &operator =(const SarSegmentSeqnum &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SAR_SEGMENT_SEQNUM_H
