#include <submit_sm.h>

namespace smpp {

SubmitSm::SubmitSm() :
  Request(CommandLength(min_length),
          CommandId(CommandId::SubmitSm),
          SequenceNumber::Min) {

}

SubmitSm::SubmitSm(const SequenceNumber &sequence_number,
                   const ServiceType &service_type,
                   const SmeAddress &source_addr,
                   const SmeAddress &destination_addr,
                   const EsmClass &esm_class,
                   const ProtocolId &protocol_id,
                   const PriorityFlag &priority_flag,
                   const Time &schedule_delivery_time,
                   const Time &validity_period,
                   const RegisteredDelivery &registered_delivery,
                   const ReplaceIfPresentFlag &replace_if_present_flag,
                   const DataCoding &data_coding,
                   const SmDefaultMsgId &sm_default_msg_id,
                   const ShortMessage &short_message) :
  Request(CommandLength(min_length),
          CommandId(CommandId::SubmitSm),
          sequence_number),
  service_type(service_type),
  source_addr(source_addr),
  destination_addr(destination_addr),
  esm_class(esm_class),
  protocol_id(protocol_id),
  priority_flag(priority_flag),
  schedule_delivery_time(schedule_delivery_time),
  validity_period(validity_period),
  registered_delivery(registered_delivery),
  replace_if_present_flag(replace_if_present_flag),
  data_coding(data_coding),
  sm_default_msg_id(sm_default_msg_id),
  short_message(short_message) {
  Header::updateLength(service_type.length() +
                       source_addr.getAddress().length() +
                       destination_addr.getAddress().length() +
                       schedule_delivery_time.length() +
                       validity_period.length() +
                       short_message.length());
}

SubmitSm::~SubmitSm() {

}

} // namespace smpp
