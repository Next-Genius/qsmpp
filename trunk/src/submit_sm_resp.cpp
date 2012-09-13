#include <submit_sm_resp.h>

namespace smpp {

SubmitSmResp::SubmitSmResp() :
    Response(CommandLength(min_length),
             CommandId(CommandId::SubmitSmResp),
             CommandStatus(CommandStatus::ESME_ROK),
             SequenceNumber::Min) {

}

SubmitSmResp::SubmitSmResp(const CommandStatus &command_status,
                           const SequenceNumber &sequence_number,
                           const MessageId &message_id) :
  Response(CommandLength(min_length),
           CommandId(CommandId::SubmitSmResp),
           command_status,
           sequence_number),
  message_id(message_id) {
  Header::updateLength(message_id.length());
}


SubmitSmResp::~SubmitSmResp()
{
}

} // namespace smpp
