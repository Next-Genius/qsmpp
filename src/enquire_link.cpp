#include <enquire_link.h>

namespace smpp {

EnquireLink::EnquireLink() :
  Header(CommandLength(min_length),
         CommandId(CommandId::EnquireLink),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

EnquireLink::EnquireLink(const SequenceNumber &sequence_number) :
  Header(CommandLength(min_length),
         CommandId(CommandId::EnquireLink),
         CommandStatus(CommandStatus::ESME_ROK),
         sequence_number) {

}

EnquireLink::~EnquireLink() {

}

} // namespace smpp
