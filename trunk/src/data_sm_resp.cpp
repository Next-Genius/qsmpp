#include <data_sm_resp.h>

namespace smpp {

DataSmResp::DataSmResp() :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::DataSmResp),
             CommandStatus(CommandStatus::ESME_ROK),
             SequenceNumber::Min) {

}

DataSmResp::DataSmResp(const CommandStatus &command_status,
                       const SequenceNumber &sequence_number,
                       const MessageId &message_id) :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::DataSmResp),
             command_status,
             sequence_number),
  message_id(message_id) {
  Header::updateLength(message_id.length());
}

DataSmResp::~DataSmResp() {

}

} // namespace smpp
