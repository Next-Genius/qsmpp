#include <replace_sm.h>

namespace smpp {

ReplaceSm::ReplaceSm() :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::ReplaceSm),
             CommandStatus(CommandStatus::ESME_ROK),
             SequenceNumber::Min) {

}

ReplaceSm::ReplaceSm(const SequenceNumber &sequence_number,
                     const MessageId &message_id,
                     const SmeAddress &source_addr,
                     const Time &schedule_delivery_time,
                     const Time &validity_period,
                     const RegisteredDelivery &registered_delivery,
                     const SmDefaultMsgId &sm_default_msg_id,
                     const ShortMessage &short_message) :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::ReplaceSm),
             CommandStatus(CommandStatus::ESME_ROK),
             sequence_number),
  message_id(message_id),
  source_addr(source_addr),
  schedule_delivery_time(schedule_delivery_time),
  validity_period(validity_period),
  registered_delivery(registered_delivery),
  sm_default_msg_id(sm_default_msg_id),
  short_message(short_message) {
  Header::updateLength(message_id.length() +
                       source_addr.getAddress().length() +
                       schedule_delivery_time.length() +
                       validity_period.length() +
                       short_message.length());
}

ReplaceSm::~ReplaceSm() {

}

} // namespace smpp
