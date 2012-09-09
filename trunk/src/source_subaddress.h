#ifndef QSMPP_SOURCE_SUBADDRESS_H
#define QSMPP_SOURCE_SUBADDRESS_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SourceSubaddress : public TLV {
  octetString value;
public:
  SourceSubaddress(const octetString &value = octetString());

  SourceSubaddress(const SourceSubaddress &other);

  bool operator ==(const SourceSubaddress &other) const;

  bool operator !=(const SourceSubaddress &other) const;

  SourceSubaddress &operator =(const SourceSubaddress &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SOURCE_SUBADDRESS_H
