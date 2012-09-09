#ifndef QSMPP_CALLBACK_NUM_ATAG_H
#define QSMPP_CALLBACK_NUM_ATAG_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT CallbackNumAtag : public TLV {
  octetString value;
public:
  CallbackNumAtag(const octetString &value = octetString());

  CallbackNumAtag(const CallbackNumAtag &other);

  bool operator ==(const CallbackNumAtag &other) const;

  bool operator !=(const CallbackNumAtag &other) const;

  CallbackNumAtag &operator =(const CallbackNumAtag &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_CALLBACK_NUM_ATAG_H
