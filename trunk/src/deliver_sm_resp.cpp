#include <deliver_sm_resp.h>

namespace smpp {

DeliverSmResp::DeliverSmResp() :
  Response(CommandLength(min_length),
           CommandId(CommandId::DeliverSmResp),
           CommandStatus(CommandStatus::ESME_ROK),
           SequenceNumber::Min) {

}

DeliverSmResp::DeliverSmResp(const CommandStatus &command_status,
                             const SequenceNumber &sequence_number,
                             const MessageId &message_id) :
  Response(CommandLength(min_length),
           CommandId(CommandId::DeliverSmResp),
           command_status,
           sequence_number),
  message_id(message_id) {
  Header::updateLength(message_id.length());
}

DeliverSmResp::~DeliverSmResp() {

}

} // namespace smpp
