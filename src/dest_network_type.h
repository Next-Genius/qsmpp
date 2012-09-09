#ifndef QSMPP_DEST_NETWORK_TYPE_H
#define QSMPP_DEST_NETWORK_TYPE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DestNetworkType : public TLV {
  quint8 value;
public:
  DestNetworkType(const quint8 value = 0);

  DestNetworkType(const DestNetworkType &other);

  bool operator ==(const DestNetworkType &other) const;

  bool operator !=(const DestNetworkType &other) const;

  DestNetworkType &operator =(const DestNetworkType &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DEST_NETWORK_TYPE_H
