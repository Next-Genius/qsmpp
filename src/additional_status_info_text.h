#ifndef QSMPP_ADDITIONAL_STATUS_INFO_TEXT_H
#define QSMPP_ADDITIONAL_STATUS_INFO_TEXT_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT AdditionalStatusInfoText : public TLV {
  CoctetString value;
public:
  AdditionalStatusInfoText(const CoctetString &value = "");

  AdditionalStatusInfoText(const AdditionalStatusInfoText &other);

  bool operator ==(const AdditionalStatusInfoText &other) const;

  bool operator !=(const AdditionalStatusInfoText &other) const;

  AdditionalStatusInfoText &operator =(
    const AdditionalStatusInfoText &other);

  void setValue(const CoctetString &value);

  CoctetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_ADDITIONAL_STATUS_INFO_TEXT_H
