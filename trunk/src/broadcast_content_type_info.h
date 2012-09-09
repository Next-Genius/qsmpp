#ifndef QSMPP_BROADCAST_CONTENT_TYPE_INFO_H
#define QSMPP_BROADCAST_CONTENT_TYPE_INFO_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BroadcastContentTypeInfo : public TLV {
  octetString value;
public:
  BroadcastContentTypeInfo(const octetString &value = octetString());

  BroadcastContentTypeInfo(const BroadcastContentTypeInfo &other);

  bool operator ==(const BroadcastContentTypeInfo &other) const;

  bool operator !=(const BroadcastContentTypeInfo &other) const;

  BroadcastContentTypeInfo &operator =(
    const BroadcastContentTypeInfo &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BROADCAST_CONTENT_TYPE_INFO_H
