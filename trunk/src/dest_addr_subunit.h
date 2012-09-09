#ifndef QSMPP_DEST_ADDR_SUBUNIT_H
#define QSMPP_DEST_ADDR_SUBUNIT_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DestAddrSubunit : public TLV {
  quint8 value;
public:
  DestAddrSubunit(quint8 value = 0);

  DestAddrSubunit(const DestAddrSubunit &other);

  bool operator ==(const DestAddrSubunit &other) const;

  bool operator !=(const DestAddrSubunit &other) const;

  DestAddrSubunit &operator =(const DestAddrSubunit &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DEST_ADDR_SUBUNIT_H
