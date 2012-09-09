#ifndef QSMPP_SOURCE_TELEMATICS_ID_H
#define QSMPP_SOURCE_TELEMATICS_ID_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SourceTelematicsId : public TLV {
  quint8 value;
public:
  SourceTelematicsId(quint8 value = 0);

  SourceTelematicsId(const SourceTelematicsId &other);

  bool operator ==(const SourceTelematicsId &other) const;

  bool operator !=(const SourceTelematicsId &other) const;

  SourceTelematicsId &operator =(const SourceTelematicsId &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SOURCE_TELEMATICS_ID_H
