#ifndef QSMPP_SOURCE_PORT_H
#define QSMPP_SOURCE_PORT_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SourcePort : public TLV {
  quint16 value;
public:
  SourcePort(quint16 value = 0);

  SourcePort(const SourcePort &other);

  bool operator ==(const SourcePort &other) const;

  bool operator !=(const SourcePort &other) const;

  SourcePort &operator =(const SourcePort &other);

  void setValue(quint16 value);

  quint16 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SOURCE_PORT_H
