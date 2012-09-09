#ifndef QSMPP_CALLBACK_NUM_H
#define QSMPP_CALLBACK_NUM_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT CallbackNum : public TLV {
  octetString value;
public:
  CallbackNum(const octetString &value = octetString());

  CallbackNum(const CallbackNum &other);

  bool operator ==(const CallbackNum &other) const;

  bool operator !=(const CallbackNum &other) const;

  CallbackNum &operator =(const CallbackNum &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_CALLBACK_NUM_H
