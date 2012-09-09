#ifndef QSMPP_SOURCE_NETWORK_TYPE_H
#define QSMPP_SOURCE_NETWORK_TYPE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SourceNetworkType : public TLV {
  quint8 value;
public:
  SourceNetworkType(quint8 value = 0);

  SourceNetworkType(const SourceNetworkType &other);

  bool operator ==(const SourceNetworkType &other) const;

  bool operator !=(const SourceNetworkType &other) const;

  SourceNetworkType &operator =(const SourceNetworkType &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SOURCE_NETWORK_TYPE_H
