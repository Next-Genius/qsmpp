#ifndef QSMPP_CALLBACK_NUM_PRES_IND_H
#define QSMPP_CALLBACK_NUM_PRES_IND_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT CallbackNumPresInd : public TLV {
  quint8 value;
public:
  CallbackNumPresInd(quint8 value = 0);

  CallbackNumPresInd(const CallbackNumPresInd &other);

  bool operator ==(const CallbackNumPresInd &other) const;

  bool operator !=(const CallbackNumPresInd &other) const;

  CallbackNumPresInd &operator =(const CallbackNumPresInd &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_CALLBACK_NUM_PRES_IND_H
