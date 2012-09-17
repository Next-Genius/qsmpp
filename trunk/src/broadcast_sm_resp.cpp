#include <broadcast_sm_resp.h>

namespace smpp {

BroadcastSmResp::BroadcastSmResp() :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::BroadcastSmResp),
             CommandStatus(CommandStatus::ESME_ROK),
             SequenceNumber::Min) {

}

BroadcastSmResp::BroadcastSmResp(const CommandStatus &command_status,
                                 const SequenceNumber &sequence_number,
                                 const MessageId &message_id) :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::BroadcastSmResp),
             command_status,
             sequence_number),
  message_id(message_id) {
  Header::updateLength(message_id.length());
}

BroadcastSmResp::~BroadcastSmResp() {
}

} // namespace smpp
