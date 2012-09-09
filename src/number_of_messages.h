#ifndef QSMPP_NUMBER_OF_MESSAGES_H
#define QSMPP_NUMBER_OF_MESSAGES_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT NumberOfMessages : public TLV {
  quint8 value;
public:
  NumberOfMessages(quint8 value = 0);

  NumberOfMessages(const NumberOfMessages &other);

  bool operator ==(const NumberOfMessages &other) const;

  bool operator !=(const NumberOfMessages &other) const;

  NumberOfMessages &operator =(const NumberOfMessages &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_NUMBER_OF_MESSAGES_H
