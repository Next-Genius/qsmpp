#include <submit_multi_resp.h>

namespace smpp {

SubmitMultiResp::SubmitMultiResp() :
  Response(CommandLength(min_length),
           CommandId(CommandId::SubmitMultiResp),
           CommandStatus(CommandStatus::ESME_ROK),
           SequenceNumber::Min) {

}

SubmitMultiResp::SubmitMultiResp(const CommandStatus &command_status,
                                 const SequenceNumber &sequence_number,
                                 const MessageId &message_id) :
  Response(CommandLength(min_length),
           CommandId(CommandId::SubmitMultiResp),
           command_status,
           sequence_number),
  message_id(message_id) {
  Header::updateLength(message_id.length());
}

SubmitMultiResp::~SubmitMultiResp() {
}

} // namespace smpp
