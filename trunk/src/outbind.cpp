#include <outbind.h>

namespace smpp {

Outbind::Outbind() :
  Header(CommandLength(min_length),
         CommandId(CommandId::Outbind),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

Outbind::Outbind(const SequenceNumber &sequence_number,
                 const SystemId &system_id,
                 const Password &password) :
  Header(CommandLength(min_length),
         CommandId(CommandId::Outbind),
         CommandStatus(CommandStatus::ESME_ROK),
         sequence_number),
  system_id(system_id),
  password(password) {
  Header::updateLength(system_id.length() + password.length());
}

Outbind::~Outbind() {

}

} // namespace smpp
