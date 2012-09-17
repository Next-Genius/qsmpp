#include <query_broadcast_sm.h>

namespace smpp {

QueryBroadcastSm::QueryBroadcastSm() :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::QueryBroadcastSm),
             CommandStatus(CommandStatus::ESME_ROK),
             SequenceNumber::Min) {

}

QueryBroadcastSm::QueryBroadcastSm(const SequenceNumber &sequence_number,
                                   const MessageId &message_id,
                                   const SmeAddress &source_addr) :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::QueryBroadcastSm),
             CommandStatus(CommandStatus::ESME_ROK),
             sequence_number),
  message_id(message_id),
  source_addr(source_addr) {
  Header::updateLength(message_id.length() +
                       source_addr.getAddress().length());
}


QueryBroadcastSm::~QueryBroadcastSm() {

}

} // namespace smpp
