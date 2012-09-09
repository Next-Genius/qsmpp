#ifndef QSMPP_PAYLOAD_TYPE_H
#define QSMPP_PAYLOAD_TYPE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT PayloadType : public TLV {
  quint8 value;
public:
  PayloadType(quint8 value = 0);

  PayloadType(const PayloadType &other);

  bool operator ==(const PayloadType &other) const;

  bool operator !=(const PayloadType &other) const;

  PayloadType &operator =(const PayloadType &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_PAYLOAD_TYPE_H
