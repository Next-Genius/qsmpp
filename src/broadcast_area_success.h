#ifndef QSMPP_BROADCAST_AREA_SUCCESS_H
#define QSMPP_BROADCAST_AREA_SUCCESS_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BroadcastAreaSuccess : public TLV {
  quint8 value;
public:
  BroadcastAreaSuccess(quint8 value = 0);

  BroadcastAreaSuccess(const BroadcastAreaSuccess &other);

  bool operator ==(const BroadcastAreaSuccess &other) const;

  bool operator !=(const BroadcastAreaSuccess &other) const;

  BroadcastAreaSuccess &operator =(const BroadcastAreaSuccess &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BROADCAST_AREA_SUCCESS_H
