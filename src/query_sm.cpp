#include <query_sm.h>

namespace smpp {

QuerySm::QuerySm() :
  Header(CommandLength(min_length),
         CommandId(CommandId::QuerySm),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

QuerySm::QuerySm(const SequenceNumber &sequence_number,
                 const MessageId &message_id,
                 const SmeAddress &source_addr) :
  Header(CommandLength(min_length),
         CommandId(CommandId::QuerySm),
         CommandStatus(CommandStatus::ESME_ROK),
         sequence_number),
  message_id(message_id),
  source_addr(source_addr) {
  Header::updateLength(message_id.length() +
                       source_addr.getAddress().length());
}

QuerySm::~QuerySm() {
}

} // namespace smpp
