#ifndef QSMPP_DEST_PORT_H
#define QSMPP_DEST_PORT_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DestPort : public TLV {
  quint16 value;
public:
  DestPort(quint16 value = 0);

  DestPort(const DestPort &);

  bool operator ==(const DestPort &other) const;

  bool operator !=(const DestPort &other) const;

  DestPort &operator =(const DestPort &other);

  void setValue(quint16 value);

  quint16 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DEST_PORT_H
