#ifndef QSMPP_DISPLAY_TIME_H
#define QSMPP_DISPLAY_TIME_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DisplayTime : public TLV {
  quint8 value;
public:
  DisplayTime(const quint8 value = 0);

  DisplayTime(const DisplayTime &other);

  bool operator ==(const DisplayTime &other) const;

  bool operator !=(const DisplayTime &other) const;

  DisplayTime &operator =(const DisplayTime &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DISPLAY_TIME_H
