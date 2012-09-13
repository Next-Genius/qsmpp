#ifndef SMPP_DATA_SM_H
#define SMPP_DATA_SM_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class DataSm : public Request {
  ServiceType service_type;
  SmeAddress source_addr;
  SmeAddress destination_addr;
  EsmClass esm_class;
  RegisteredDelivery registered_delivery;
  DataCoding data_coding;

public:
  const static int min_length = 26;
  DataSm();

  DataSm(const SequenceNumber &sequence_number,
         const ServiceType &service_type,
         const SmeAddress &source_addr,
         const SmeAddress &destination_addr,
         const EsmClass &esm_class,
          const RegisteredDelivery &registered_delivery,
         const DataCoding &data_coding);

  ~DataSm();

  //
  // Mutating
  //

  void setServiceType(const ServiceType &p) {
    int diff = p.length() - service_type.length();
    service_type = p;
    Header::updateLength(diff);
  }

  void setServiceType(const char *p) {
    int diff = strlen(p) - service_type.length();
    service_type = p;
    Header::updateLength(diff);
  }

  void setSourceAddr(const SmeAddress &p) {
    int diff = p.getAddress().length() - source_addr.getAddress().length();
    source_addr = p;
    Header::updateLength(diff);
  }

  void setSourceAddr(const Address &p) {
    int diff = p.length() - source_addr.getAddress().length();
    source_addr = SmeAddress(Ton(Ton::Unknown),
                             Npi(Npi::Unknown),
                             p);
    Header::updateLength(diff);
  }

  void setDestinationAddr(const SmeAddress &p) {
    int diff = p.getAddress().length() - destination_addr.getAddress().length();
    destination_addr = p;
    Header::updateLength(diff);
  }

  void setDestinationAddr(const Address &p) {
    int diff = p.length() - destination_addr.getAddress().length();
    destination_addr = SmeAddress(Ton(Ton::Unknown),
                                  Npi(Npi::Unknown),
                                  p);
    Header::updateLength(diff);
  }

  void setEsmClass(const int &p) { esm_class = p; }

  void setRegisteredDelivery(const RegisteredDelivery &p) {
    registered_delivery = p;
  }

  void setDataCoding(const DataCoding &p) { data_coding = p; }

  //
  // Accessing
  //

  const ServiceType &getServiceType() const { return service_type; }

  const SmeAddress &getSourceAddr() const { return source_addr; }

  const SmeAddress &getDestinationAddr() const { return destination_addr; }

  const EsmClass &getEsmClass() const { return esm_class; }

  const RegisteredDelivery &getRegisteredDelivery() const {
    return registered_delivery;
  }

  const DataCoding &getDataCoding() const { return data_coding; }
};

} // namespace smpp

#endif // SMPP_DATA_SM_H
