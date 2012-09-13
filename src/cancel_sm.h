#ifndef SMPP_CANCEL_SM_H
#define SMPP_CANCEL_SM_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class CancelSm : public Request {
    ServiceType service_type;
    MessageId message_id;
    SmeAddress source_addr;
    SmeAddress destination_addr;

  public:
    const static int min_length = 24;

    CancelSm();

    CancelSm(const SequenceNumber &sequence_number,
             const ServiceType &service_type,
             const MessageId &message_id,
             const SmeAddress &source_addr,
             const SmeAddress &destination_addr);

    ~CancelSm();

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

    void setMessageId(const MessageId &p) {
        int diff = p.length() - message_id.length();
        message_id = p;
        Header::updateLength(diff);
    }

    void setMessageId(const char *p) {
        int diff = strlen(p) - message_id.length();
        message_id = p;
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
        int diff =
            p.getAddress().length() - destination_addr.getAddress().length();
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

    //
    // Accessing
    //

    const ServiceType &getServiceType() const { return service_type; }

    const MessageId &getMessageId() const { return message_id; }

    const SmeAddress &getSourceAddr() const { return source_addr; }

    const SmeAddress &getDestinationAddr() const { return destination_addr; }
};

} // namespace smpp

#endif // SMPP_CANCEL_SM_H
