#ifndef QSMPP_BROADCAST_AREA_IDENTIFIER_H
#define QSMPP_BROADCAST_AREA_IDENTIFIER_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BroadcastAreaIdentifier : public TLV {
  octetString value;
public:
  BroadcastAreaIdentifier(const octetString &value = octetString());

  BroadcastAreaIdentifier(const BroadcastAreaIdentifier &other);

  bool operator ==(const BroadcastAreaIdentifier &other) const;

  bool operator !=(const BroadcastAreaIdentifier &other) const;

  BroadcastAreaIdentifier &operator =(const BroadcastAreaIdentifier &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BROADCAST_AREA_IDENTIFIER_H
