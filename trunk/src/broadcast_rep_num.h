#ifndef QSMPP_BROADCAST_REP_NUM_H
#define QSMPP_BROADCAST_REP_NUM_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BroadcastRepNum : public TLV {
  quint16 value;
public:
  BroadcastRepNum(quint16 value = 0);

  BroadcastRepNum(const BroadcastRepNum &other);

  bool operator ==(const BroadcastRepNum &other) const;

  bool operator !=(const BroadcastRepNum &other) const;

  BroadcastRepNum &operator =(const BroadcastRepNum &other);

  void setValue(quint16 value);

  quint16 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BROADCAST_REP_NUM_H
