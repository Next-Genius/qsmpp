#ifndef QSMPP_DEST_ADDR_NP_RESOLUTION_H
#define QSMPP_DEST_ADDR_NP_RESOLUTION_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DestAddrNpResolution : public TLV {
  quint8 value;
public:
  DestAddrNpResolution(quint8 value = 0);

  DestAddrNpResolution(const DestAddrNpResolution &other);

  bool operator ==(const DestAddrNpResolution &other) const;

  bool operator !=(const DestAddrNpResolution &other) const;

  DestAddrNpResolution &operator =(const DestAddrNpResolution &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DEST_ADDR_NP_RESOLUTION_H
