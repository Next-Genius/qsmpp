#ifndef QSMPP_SAR_MSG_REF_NUM_H
#define QSMPP_SAR_MSG_REF_NUM_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SarMsgRefNum : public TLV {
  quint16 value;
public:
  SarMsgRefNum(quint16 value = 0);

  SarMsgRefNum(const SarMsgRefNum &other);

  bool operator ==(const SarMsgRefNum &other) const;

  bool operator !=(const SarMsgRefNum &other) const;

  SarMsgRefNum &operator =(const SarMsgRefNum &other);

  void setValue(quint16 value);

  quint16 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SAR_MSG_REF_NUM_H
