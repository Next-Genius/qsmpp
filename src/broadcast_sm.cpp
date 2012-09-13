#include <broadcast_sm.h>

namespace smpp {

BroadcastSm::BroadcastSm() :
  Request(CommandLength(min_length),
          CommandId(CommandId::BroadcastSm),
          SequenceNumber::Min) {

}

BroadcastSm::BroadcastSm(const SequenceNumber &sequence_number,
                         const ServiceType &service_type,
                         const SmeAddress &source_addr,
                         const MessageId &message_id,
                         const PriorityFlag &priority_flag,
                         const Time &schedule_delivery_time,
                         const Time &validity_period,
                         const ReplaceIfPresentFlag &replace_if_present_flag,
                         const DataCoding &data_coding,
                         const SmDefaultMsgId &sm_default_msg_id) :
  Request(CommandLength(min_length),
          CommandId(CommandId::BroadcastSm),
          sequence_number),
  service_type(service_type),
  source_addr(source_addr),
  message_id(message_id),
  priority_flag(priority_flag),
  schedule_delivery_time(schedule_delivery_time),
  validity_period(validity_period),
  replace_if_present_flag(replace_if_present_flag),
  data_coding(data_coding),
  sm_default_msg_id(sm_default_msg_id) {
  Header::updateLength(service_type.length() +
                       source_addr.getAddress().length() +
                       message_id.length() +
                       schedule_delivery_time.length() +
                       validity_period.length());
}

BroadcastSm::~BroadcastSm() {

}

} // namespace smpp
