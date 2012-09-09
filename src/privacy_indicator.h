#ifndef QSMPP_PRIVACY_INDICATOR_H
#define QSMPP_PRIVACY_INDICATOR_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT PrivacyIndicator : public TLV {
  quint8 value;
public:
  PrivacyIndicator(const quint8 value = 0);

  PrivacyIndicator(const PrivacyIndicator &other);

  bool operator ==(const PrivacyIndicator &other) const;

  bool operator !=(const PrivacyIndicator &other) const;

  PrivacyIndicator &operator =(const PrivacyIndicator &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_PRIVACY_INDICATOR_H
