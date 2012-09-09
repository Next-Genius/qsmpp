#ifndef QSMPP_SOURCE_NETWORK_ID_H
#define QSMPP_SOURCE_NETWORK_ID_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SourceNetworkId : public TLV {
  CoctetString value;
public:
  SourceNetworkId(const CoctetString &value = "");

  SourceNetworkId(const SourceNetworkId &other);

  bool operator ==(const SourceNetworkId &other) const;

  bool operator !=(const SourceNetworkId &other) const;

  SourceNetworkId &operator =(const SourceNetworkId &other);

  void setValue(const CoctetString &value);

  CoctetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SOURCE_NETWORK_ID_H
