#ifndef QSMPP_DEST_BEARER_TYPE_H
#define QSMPP_DEST_BEARER_TYPE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DestBearerType : public TLV {
  quint8 value;
public:
  DestBearerType(quint8 value = 0);

  DestBearerType(const DestBearerType &other);

  bool operator ==(const DestBearerType &other) const;

  bool operator !=(const DestBearerType &other) const;

  DestBearerType &operator =(const DestBearerType &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DEST_BEARER_TYPE_H
