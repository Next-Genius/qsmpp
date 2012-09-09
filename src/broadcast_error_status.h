#ifndef QSMPP_BROADCAST_ERROR_STATUS_H
#define QSMPP_BROADCAST_ERROR_STATUS_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BroadcastErrorStatus : public TLV {
  quint32 value;
public:
  BroadcastErrorStatus(quint32 value = 0);

  BroadcastErrorStatus(const BroadcastErrorStatus &other);

  bool operator ==(const BroadcastErrorStatus &other) const;

  bool operator !=(const BroadcastErrorStatus &other) const;

  BroadcastErrorStatus &operator =(const BroadcastErrorStatus &other);

  void setValue(quint32 value);

  quint32 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BROADCAST_ERROR_STATUS_H
