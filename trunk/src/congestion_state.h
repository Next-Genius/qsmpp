#ifndef QSMPP_CONGESTION_STATE_H
#define QSMPP_CONGESTION_STATE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT CongestionState : public TLV {
  quint8 value;
public:
  CongestionState(quint8 value = 0);

  CongestionState(const CongestionState &other);

  bool operator ==(const CongestionState &other) const;

  bool operator !=(const CongestionState &other) const;

  CongestionState &operator =(const CongestionState &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_CONGESTION_STATE_H
