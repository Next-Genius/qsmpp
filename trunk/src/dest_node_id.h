#ifndef QSMPP_DEST_NODE_ID_H
#define QSMPP_DEST_NODE_ID_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DestNodeId : public TLV {
  octetString value;
public:
  DestNodeId(const octetString &value = octetString());

  DestNodeId(const DestNodeId &other);

  bool operator ==(const DestNodeId &other) const;

  bool operator !=(const DestNodeId &other) const;

  DestNodeId &operator =(const DestNodeId &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DEST_NODE_ID_H
