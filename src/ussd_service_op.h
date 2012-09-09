#ifndef QSMPP_USSD_SERVICE_OP_H
#define QSMPP_USSD_SERVICE_OP_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT UssdServiceOp : public TLV {
  quint8 value;
public:
  UssdServiceOp(const quint8 value = 0);

  UssdServiceOp(const UssdServiceOp &other);

  bool operator ==(const UssdServiceOp &other) const;

  bool operator !=(const UssdServiceOp &other) const;

  UssdServiceOp &operator =(const UssdServiceOp &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_USSD_SERVICE_OP_H
