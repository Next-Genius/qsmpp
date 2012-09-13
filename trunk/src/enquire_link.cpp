#include <enquire_link.h>

namespace smpp {

EnquireLink::EnquireLink() :
  Request(CommandLength(min_length),
          CommandId(CommandId::EnquireLink),
          SequenceNumber::Min) {

}

EnquireLink::EnquireLink(const SequenceNumber &sequence_number) :
  Request(CommandLength(min_length),
          CommandId(CommandId::EnquireLink),
          sequence_number) {

}

EnquireLink::~EnquireLink() {

}

} // namespace smpp
