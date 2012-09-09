#ifndef QSMPP_SOURCE_BEARER_TYPE_H
#define QSMPP_SOURCE_BEARER_TYPE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SourceBearerType : public TLV {
  quint8 value;
public:
  SourceBearerType(const quint8 value = 0);

  SourceBearerType(const SourceBearerType &other);

  bool operator ==(const SourceBearerType &other) const;

  bool operator !=(const SourceBearerType &other) const;

  SourceBearerType &operator =(const SourceBearerType &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SOURCE_BEARER_TYPE_H
