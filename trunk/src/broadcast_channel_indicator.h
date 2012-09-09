#ifndef QSMPP_BROADCAST_CHANNEL_INDICATOR_H
#define QSMPP_BROADCAST_CHANNEL_INDICATOR_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BroadcastChannelIndicator : public TLV {
  quint8 value;
public:
  BroadcastChannelIndicator(quint8 value = 0);

  BroadcastChannelIndicator(const BroadcastChannelIndicator &other);

  bool operator ==(const BroadcastChannelIndicator &other) const;

  bool operator !=(const BroadcastChannelIndicator &other) const;

  BroadcastChannelIndicator &operator =(
    const BroadcastChannelIndicator &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BROADCAST_CHANNEL_INDICATOR_H
