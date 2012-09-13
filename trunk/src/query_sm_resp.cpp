#include <query_sm_resp.h>

namespace smpp {

QuerySmResp::QuerySmResp() :
  Response(CommandLength(min_length),
           CommandId(CommandId::QuerySmResp),
           CommandStatus(CommandStatus::ESME_ROK),
           SequenceNumber::Min) {

}

QuerySmResp::QuerySmResp(const CommandStatus &command_status,
                         const SequenceNumber &sequence_number,
                         const MessageId &message_id,
                         const Time &final_date,
                         const MessageState &message_state,
                         const ErrorCode &error_code) :
  Response(CommandLength(min_length),
           CommandId(CommandId::QuerySmResp),
           command_status,
           sequence_number),
  message_id(message_id),
  final_date(final_date),
  message_state(message_state),
  error_code(error_code) {
  Header::updateLength(message_id.length() + final_date.length());
}


QuerySmResp::~QuerySmResp()
{
}

} // namespace smpp
