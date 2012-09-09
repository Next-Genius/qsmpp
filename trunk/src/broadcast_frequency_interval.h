#ifndef QSMPP_BROADCAST_FREQUENCY_INTERVAL_H
#define QSMPP_BROADCAST_FREQUENCY_INTERVAL_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BroadcastFrequencyInterval : public TLV {
  octetString value;
public:
  BroadcastFrequencyInterval(const octetString &value = octetString());

  BroadcastFrequencyInterval(const BroadcastFrequencyInterval &other);

  bool operator ==(const BroadcastFrequencyInterval &other) const;

  bool operator !=(const BroadcastFrequencyInterval &other) const;

  BroadcastFrequencyInterval &operator =(
    const BroadcastFrequencyInterval &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BROADCAST_FREQUENCY_INTERVAL_H
