#include <unbind.h>

namespace smpp {

Unbind::Unbind() :
  Header(CommandLength(min_length),
         CommandId(CommandId::Unbind),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

Unbind::Unbind(const SequenceNumber &sequence_number) :
  Header(CommandLength(min_length),
         CommandId(CommandId::Unbind),
         CommandStatus(CommandStatus::ESME_ROK),
         sequence_number) {

}

Unbind::~Unbind() {

}

} // namespace smpp
