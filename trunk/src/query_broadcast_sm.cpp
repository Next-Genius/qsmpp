#include <query_broadcast_sm.h>

namespace smpp {

QueryBroadcastSm::QueryBroadcastSm() :
  Request(CommandLength(min_length),
          CommandId(CommandId::QueryBroadcastSm),
          SequenceNumber::Min) {

}

QueryBroadcastSm::QueryBroadcastSm(const SequenceNumber &sequence_number,
                                   const MessageId &message_id,
                                   const SmeAddress &source_addr) :
  Request(CommandLength(min_length),
          CommandId(CommandId::QueryBroadcastSm),
          sequence_number),
  message_id(message_id),
  source_addr(source_addr) {
  Header::updateLength(message_id.length() +
                       source_addr.getAddress().length());
}


QueryBroadcastSm::~QueryBroadcastSm() {

}

} // namespace smpp
