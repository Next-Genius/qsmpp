#include <cancel_sm.h>

namespace smpp {

CancelSm::CancelSm() :
  Request(CommandLength(min_length),
          CommandId(CommandId::CancelSm),
          SequenceNumber::Min) {

}

CancelSm::CancelSm(const SequenceNumber &sequence_number,
                   const ServiceType &service_type,
                   const MessageId &message_id,
                   const SmeAddress &source_addr,
                   const SmeAddress &destination_addr) :
  Request(CommandLength(min_length),
          CommandId(CommandId::CancelSm),
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
