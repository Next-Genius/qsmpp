#ifndef QSMPP_BROADCAST_END_TIME_H
#define QSMPP_BROADCAST_END_TIME_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BroadcastEndTime : public TLV {
  CoctetString value;
public:
  BroadcastEndTime(const CoctetString &value = "");

  BroadcastEndTime(const BroadcastEndTime &other);

  bool operator ==(const BroadcastEndTime &other) const;

  bool operator !=(const BroadcastEndTime &other) const;

  BroadcastEndTime &operator =(const BroadcastEndTime &other);

  void setValue(const CoctetString &value);

  CoctetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BROADCAST_END_TIME_H
