#include <bind_transmitter_resp.h>

namespace smpp {

BindTransmitterResp::BindTransmitterResp() :
  Response(CommandLength(min_length),
           CommandId(CommandId::BindTransmitterResp),
           CommandStatus(CommandStatus::ESME_ROK),
           SequenceNumber::Min) {
}

BindTransmitterResp::BindTransmitterResp(const CommandStatus &command_status,
                                         const SequenceNumber &sequence_number,
                                         const SystemId &system_id) :
  Response(CommandLength(min_length),
           CommandId(CommandId::BindTransmitterResp),
           command_status,
           sequence_number),
  system_id(system_id) {
  Header::updateLength(system_id.length());
}

BindTransmitterResp::~BindTransmitterResp() {

}

} // namespace smpp
