#include <query_sm.h>

namespace smpp {

QuerySm::QuerySm() :
  Request(CommandLength(min_length),
          CommandId(CommandId::QuerySm),
          SequenceNumber::Min) {

}

QuerySm::QuerySm(const SequenceNumber &sequence_number,
                 const MessageId &message_id,
                 const SmeAddress &source_addr) :
  Request(CommandLength(min_length),
          CommandId(CommandId::QuerySm),
          sequence_number),
  message_id(message_id),
  source_addr(source_addr) {
  Header::updateLength(message_id.length() +
                       source_addr.getAddress().length());
}

QuerySm::~QuerySm() {
}

} // namespace smpp
