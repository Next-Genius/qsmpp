#ifndef QSMPP_BROADCAST_CONTENT_TYPE_H
#define QSMPP_BROADCAST_CONTENT_TYPE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BroadcastContentType : public TLV {
  octetString value;
public:
  BroadcastContentType(const octetString &value = octetString());

  BroadcastContentType(const BroadcastContentType &other);

  bool operator ==(const BroadcastContentType &other) const;

  bool operator !=(const BroadcastContentType &other) const;

  BroadcastContentType &operator =(const BroadcastContentType &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BROADCAST_CONTENT_TYPE_H
