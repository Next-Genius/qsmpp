#ifndef QSMPP_DEST_NETWORK_ID_H
#define QSMPP_DEST_NETWORK_ID_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DestNetworkId : public TLV {
  CoctetString value;
public:
  DestNetworkId(const CoctetString &value = "");

  DestNetworkId(const DestNetworkId &other);

  bool operator ==(const DestNetworkId &other) const;

  bool operator !=(const DestNetworkId &other) const;

  DestNetworkId &operator =(const DestNetworkId &other);

  void setValue(const CoctetString &value);

  CoctetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DEST_NETWORK_ID_H
