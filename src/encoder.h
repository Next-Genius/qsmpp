#ifndef SMPP_ENCODER_H
#define SMPP_ENCODER_H

#include <bind_receiver.h>
#include <bind_receiver_resp.h>
#include <bind_transmitter.h>
#include <bind_transmitter_resp.h>
#include <bind_transceiver.h>
#include <bind_transceiver_resp.h>
#include <broadcast_sm.h>
#include <broadcast_sm_resp.h>
#include <cancel_broadcast_sm.h>
#include <cancel_broadcast_sm_resp.h>
#include <cancel_sm.h>
#include <cancel_sm_resp.h>
#include <data_sm.h>
#include <data_sm_resp.h>
#include <deliver_sm.h>
#include <deliver_sm_resp.h>
#include <enquire_link.h>
#include <enquire_link_resp.h>
#include <generic_nack.h>
#include <outbind.h>
#include <query_broadcast_sm.h>
#include <query_broadcast_sm_resp.h>
#include <query_sm.h>
#include <query_sm_resp.h>
#include <replace_sm.h>
#include <replace_sm_resp.h>
#include <submit_multi.h>
#include <submit_multi_resp.h>
#include <submit_sm.h>
#include <submit_sm_resp.h>
#include <unbind.h>
#include <unbind_resp.h>

namespace smpp {

class Encoder {
  uint8 *data;
  uint32 offset;
public:

  Encoder();

  ~Encoder();

  void reset();

  void reset(const uint32 &length);

  Encoder &operator +=(const uint32 &p);

  Encoder &operator +=(const uint16 &p);

  Encoder &operator +=(const uint8 &p);

  Encoder &operator +=(const CString &p);

  Encoder &operator +=(const ShortMessage &p);

  Encoder &operator +=(const SmeAddress &p);

  Encoder &operator +=(const MultiDestinationAddresses &p);

  Encoder &operator +=(const UnsuccessSmeColl &p);

  void addHeader(const Header &p);

  void addTlv(const Tlv &p);

  void addTlvs(const TlvList &p);

  Encoder &operator +=(const BindReceiver &p);

  Encoder &operator +=(const BindReceiverResp &p);

  Encoder &operator +=(const BindTransmitter &p);

  Encoder &operator +=(const BindTransmitterResp &p);

  Encoder &operator +=(const BindTransceiver &p);

  Encoder &operator +=(const BindTransceiverResp &p);

  Encoder &operator +=(const BroadcastSm &p);

  Encoder &operator +=(const BroadcastSmResp &p);

  Encoder &operator +=(const CancelBroadcastSm &p);

  Encoder &operator +=(const CancelBroadcastSmResp &p);

  Encoder &operator +=(const CancelSm &p);

  Encoder &operator +=(const CancelSmResp &p);

  Encoder &operator +=(const DataSm &p);

  Encoder &operator +=(const DataSmResp &p);

  Encoder &operator +=(const DeliverSm &p);

  Encoder &operator +=(const DeliverSmResp &p);

  Encoder &operator +=(const EnquireLink &p);

  Encoder &operator +=(const EnquireLinkResp &p);

  Encoder &operator +=(const GenericNack &p);

  Encoder &operator +=(const Outbind &p);

  Encoder &operator +=(const QueryBroadcastSm &p);

  Encoder &operator +=(const QueryBroadcastSmResp &p);

  Encoder &operator +=(const QuerySm &p);

  Encoder &operator +=(const QuerySmResp &p);

  Encoder &operator +=(const ReplaceSm &p);

  Encoder &operator +=(const ReplaceSmResp &p);

  Encoder &operator +=(const SubmitMulti &p);

  Encoder &operator +=(const SubmitMultiResp &p);

  Encoder &operator +=(const SubmitSm &p);

  Encoder &operator +=(const SubmitSmResp &p);

  Encoder &operator +=(const Unbind &p);

  Encoder &operator +=(const UnbindResp &p);

  Encoder &addOctetArray(const uint32 &length, const uint8 *array);

  const uint8 *get() const { return data; }

  class CopySubmitMultiAddresses {
    Encoder &encoder;
  public:
    CopySubmitMultiAddresses(Encoder &p) : encoder(p) {}
    Encoder &get() { return encoder; }
    void operator()(const MultiDestinationAddressBase *p) {
      switch(p->Type()) {
        case 0x01: {
          encoder += static_cast<uint8>(0x01);
          const SmeMultiAddress* addr =
                              static_cast<const SmeMultiAddress*>(p);
          encoder += addr->Value();
          break;
        }
        case 0x02: {
          encoder += static_cast<uint8>(0x02);
          const DistributionListAddress* addr =
                      static_cast<const DistributionListAddress*>(p);
          encoder += addr->Value();
          break;
        }
      }
    }
  };

  class CopyUnsuccessSmeColl {
      Encoder &encoder;
    public:
      CopyUnsuccessSmeColl(Encoder &p) : encoder(p) {}

      Encoder &get() { return encoder; }

      void operator()(const UnsuccessSme* p) {
        encoder += p->getSmeAddress();
        encoder += hton32(p->getError());
      }
  };
};

} // namespace smpp

#endif // SMPP_ENCODER_H
