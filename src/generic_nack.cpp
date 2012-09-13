#include <generic_nack.h>

namespace smpp {

GenericNack::GenericNack() :
  Response(CommandLength(min_length),
           CommandId(CommandId::GenericNack),
           CommandStatus(CommandStatus::ESME_ROK),
           SequenceNumber::Min) {

}

GenericNack::GenericNack(const CommandStatus &command_status,
                         const SequenceNumber &sequence_number) :
  Response(CommandLength(min_length),
           CommandId(CommandId::GenericNack),
           command_status,
           sequence_number) {

}

GenericNack::~GenericNack() {

}

} // namespace smpp
