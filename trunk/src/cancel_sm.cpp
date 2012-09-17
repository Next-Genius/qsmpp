#include <cancel_sm.h>

namespace smpp {

CancelSm::CancelSm() :
  Header(CommandLength(min_length),
         CommandId(CommandId::CancelSm),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

CancelSm::CancelSm(const SequenceNumber &sequence_number,
                   const ServiceType &service_type,
                   const MessageId &message_id,
                   const SmeAddress &source_addr,
                   const SmeAddress &destination_addr) :
  Header(CommandLength(min_length),
         CommandId(CommandId::CancelSm),
         CommandStatus(CommandStatus::ESME_ROK),
         sequence_number),
  service_type(service_type),
  message_id(message_id),
  source_addr(source_addr),
  destination_addr(destination_addr) {
  Header::updateLength(service_type.length() +
                       message_id.length() +
                       source_addr.getAddress().length() +
                       destination_addr.getAddress().length());
}

CancelSm::~CancelSm() {

}

} // namespace smpp
