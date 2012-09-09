#ifndef QSMPP_SMS_SIGNAL_H
#define QSMPP_SMS_SIGNAL_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SmsSignal : public TLV {
  quint16 value;
public:
  SmsSignal(quint16 value = 0);

  SmsSignal(const SmsSignal &other);

  bool operator ==(const SmsSignal &other) const;

  bool operator !=(const SmsSignal &other) const;

  SmsSignal &operator =(const SmsSignal &other);

  void setValue(quint16 value);

  quint16 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SMS_SIGNAL_H
