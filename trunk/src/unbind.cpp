#include <unbind.h>

namespace smpp {

Unbind::Unbind() :
  Request(CommandLength(min_length),
          CommandId(CommandId::Unbind),
          SequenceNumber::Min) {

}

Unbind::Unbind(const SequenceNumber &sequence_number) :
  Request(CommandLength(min_length),
          CommandId(CommandId::Unbind),
          sequence_number) {

}

Unbind::~Unbind() {

}

} // namespace smpp
