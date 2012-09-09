#ifndef QSMPP_DEST_SUBADDRESS_H
#define QSMPP_DEST_SUBADDRESS_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DestSubaddress : public TLV {
  octetString value;
public:
  DestSubaddress(const octetString &value = octetString());

  DestSubaddress(const DestSubaddress &other);

  bool operator ==(const DestSubaddress &other) const;

  bool operator !=(const DestSubaddress &other) const;

  DestSubaddress &operator =(const DestSubaddress &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DEST_SUBADDRESS_H
