#ifndef QSMPP_LANGUAGE_INDICATOR_H
#define QSMPP_LANGUAGE_INDICATOR_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT LanguageIndicator : public TLV {
  quint8 value;
public:
  LanguageIndicator(const quint8 value = 0);

  LanguageIndicator(const LanguageIndicator &other);

  bool operator ==(const LanguageIndicator &other) const;

  bool operator !=(const LanguageIndicator &other) const;

  LanguageIndicator &operator =(const LanguageIndicator &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_LANGUAGE_INDICATOR_H
