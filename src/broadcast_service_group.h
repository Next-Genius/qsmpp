#ifndef QSMPP_BROADCAST_SERVICE_GROUP_H
#define QSMPP_BROADCAST_SERVICE_GROUP_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BroadcastServiceGroup : public TLV {
  octetString value;
public:
  BroadcastServiceGroup(const octetString &value = octetString());

  BroadcastServiceGroup(const BroadcastServiceGroup &other);

  bool operator ==(const BroadcastServiceGroup &other) const;

  bool operator !=(const BroadcastServiceGroup &other) const;

  BroadcastServiceGroup &operator =(const BroadcastServiceGroup &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BROADCAST_SERVICE_GROUP_H
