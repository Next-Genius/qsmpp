#include <data_sm.h>

namespace smpp {

DataSm::DataSm() :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::DataSm),
             CommandStatus(CommandStatus::ESME_ROK),
             SequenceNumber::Min) {

}

DataSm::DataSm(const SequenceNumber &sequence_number,
               const ServiceType &service_type,
               const SmeAddress &source_addr,
               const SmeAddress &destination_addr,
               const EsmClass &esm_class,
               const RegisteredDelivery &registered_delivery,
               const DataCoding &data_coding) :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::DataSm),
             CommandStatus(CommandStatus::ESME_ROK),
             sequence_number),
  service_type(service_type),
  source_addr(source_addr),
  destination_addr(destination_addr),
  esm_class(esm_class),
  registered_delivery(registered_delivery),
  data_coding(data_coding) {
  Header::updateLength(service_type.length() +
                       source_addr.getAddress().length() +
                       destination_addr.getAddress().length());
}

DataSm::~DataSm() {

}

} // namespace smpp
