#ifndef QSMPP_DEST_ADDR_NP_COUNTRY_H
#define QSMPP_DEST_ADDR_NP_COUNTRY_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DestAddrNpCountry: public TLV{
  octetString value;
public:
  DestAddrNpCountry(const octetString &value = octetString());

  DestAddrNpCountry(const DestAddrNpCountry &other);

  bool operator ==(const DestAddrNpCountry &other) const;

  bool operator !=(const DestAddrNpCountry &other) const;

  DestAddrNpCountry &operator =(const DestAddrNpCountry &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DEST_ADDR_NP_COUNTRY_H
