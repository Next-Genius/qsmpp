#ifndef QSMPP_MS_VALIDITY_H
#define QSMPP_MS_VALIDITY_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT MsValidity : public TLV {
  octetString value;
public:
  MsValidity(const octetString &value = octetString());

  MsValidity(const MsValidity &other);

  bool operator ==(const MsValidity &other) const;

  bool operator !=(const MsValidity &other) const;

  MsValidity &operator =(const MsValidity &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_MS_VALIDITY_H
