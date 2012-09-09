#ifndef QSMPP_DEST_ADDR_NP_INFORMATION_H
#define QSMPP_DEST_ADDR_NP_INFORMATION_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DestAddrNpInformation : public TLV {
  octetString value;
public:
  DestAddrNpInformation(const octetString &value = octetString());

  DestAddrNpInformation(const DestAddrNpInformation &other);

  bool operator ==(const DestAddrNpInformation &other) const;

  bool operator !=(const DestAddrNpInformation &other) const;

  DestAddrNpInformation &operator =(const DestAddrNpInformation &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DEST_ADDR_NP_INFORMATION_H
