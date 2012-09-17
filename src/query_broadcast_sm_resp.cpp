#include <query_broadcast_sm_resp.h>

namespace smpp {

QueryBroadcastSmResp::QueryBroadcastSmResp() :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::QueryBroadcastSmResp),
             CommandStatus(CommandStatus::ESME_ROK),
             SequenceNumber::Min) {

}

QueryBroadcastSmResp::QueryBroadcastSmResp(const CommandStatus &command_status,
                                           const SequenceNumber &sequence_number,
                                           const MessageId &message_id,
                                           const MessageState &message_state) :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::QueryBroadcastSmResp),
             command_status,
             sequence_number),
  message_id(message_id),
  message_state(message_state) {
    Header::updateLength(message_id.length());
}

QueryBroadcastSmResp::~QueryBroadcastSmResp() {

}

} // namespace smpp
