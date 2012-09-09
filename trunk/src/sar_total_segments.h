#ifndef QSMPP_SAR_TOTAL_SEGMENTS_H
#define QSMPP_SAR_TOTAL_SEGMENTS_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SarTotalSegments : public TLV {
  quint8 value;
public:
  SarTotalSegments(quint8 value = 0);

  SarTotalSegments(const SarTotalSegments &other);

  bool operator ==(const SarTotalSegments &other) const;

  bool operator !=(const SarTotalSegments &other) const;

  SarTotalSegments &operator =(const SarTotalSegments &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SAR_TOTAL_SEGMENTS_H
