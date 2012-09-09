#ifndef QSMPP_DEST_TELEMATICS_ID_H
#define QSMPP_DEST_TELEMATICS_ID_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DestTelematicsId : public TLV {
  quint16 value;
public:
  DestTelematicsId(quint16 value = 0);

  DestTelematicsId(const DestTelematicsId &other);

  bool operator ==(const DestTelematicsId &other) const;

  bool operator !=(const DestTelematicsId &other) const;

  DestTelematicsId &operator =(const DestTelematicsId &other);

  void setValue(quint16 value);

  quint16 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DEST_TELEMATICS_ID_H
