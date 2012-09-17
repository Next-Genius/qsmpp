#include <cancel_broadcast_sm.h>

namespace smpp {

CancelBroadcastSm::CancelBroadcastSm() :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::CancelBroadcastSm),
             CommandStatus(CommandStatus::ESME_ROK),
             SequenceNumber::Min) {

}

CancelBroadcastSm::CancelBroadcastSm(const SequenceNumber &sequence_number,
                                     const ServiceType &service_type,
                                     const MessageId &message_id,
                                     const SmeAddress &source_addr) :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::CancelBroadcastSm),
             CommandStatus(CommandStatus::ESME_ROK),
             sequence_number),
  service_type(service_type),
  message_id(message_id),
  source_addr(source_addr) {
  Header::updateLength(service_type.length() +
                       message_id.length() +
                       source_addr.getAddress().length());
}

CancelBroadcastSm::~CancelBroadcastSm() {

}

} // namespace smpp
