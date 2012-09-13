#include <outbind.h>

namespace smpp {

Outbind::Outbind() :
  Request(CommandLength(min_length),
          CommandId(CommandId::Outbind),
          SequenceNumber::Min) {

}

Outbind::Outbind(const SequenceNumber &sequence_number,
                 const SystemId &system_id,
                 const Password &password) :
  Request(CommandLength(min_length),
          CommandId(CommandId::Outbind),
          sequence_number),
  system_id(system_id),
  password(password) {
  Header::updateLength(system_id.length() + password.length());
}

Outbind::~Outbind() {

}

} // namespace smpp
