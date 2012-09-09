#ifndef QSMPP_TLV_H
#define QSMPP_TLV_H

#include <constants.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT TLV {
  quint16 tag;
  quint16 length;
public:
  TLV(quint16 tag = 0,
      quint16 length = 0);

  TLV(const TLV &other);

  bool operator ==(const TLV &other) const;

  bool operator !=(const TLV &other) const;

  TLV &operator = (const TLV &other);

  void setTag(quint16 tag);

  quint16 getTag() const;

  void setLength(quint16 length);

  quint16 getLength() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // TLV_H
