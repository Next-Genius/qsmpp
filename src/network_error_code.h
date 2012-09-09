#ifndef QSMPP_NETWORK_ERROR_CODE_H
#define QSMPP_NETWORK_ERROR_CODE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT NetworkErrorCode : public TLV {
  octetString value;
public:
  NetworkErrorCode(const octetString &value = octetString());

  NetworkErrorCode(const NetworkErrorCode &other);

  bool operator ==(const NetworkErrorCode &other) const;

  bool operator !=(const NetworkErrorCode &other) const;

  NetworkErrorCode &operator =(const NetworkErrorCode &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_NETWORK_ERROR_CODE_H
