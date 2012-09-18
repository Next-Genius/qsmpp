#ifndef SMPP_DECODER_H
#define SMPP_DECODER_H

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

class Decoder {
  int pos;
  int max_pos;
  const uint8 *data;
  uint32 last_error;
public:

  Decoder();

  ~Decoder();

  void setData(const uint8 *data, const int &length);

  void clear();

  bool decode(uint32 &p);

  bool decode(uint16 &p);

  bool decode(uint8 &p);

  bool decode(CString &p);

  bool decode(uint8 *data, const int &length);

  bool decode(SmeAddress &p);

  bool decode(MultiDestinationAddresses &p);

  bool decode(UnsuccessSme &p);

  bool decode(UnsuccessSmeColl &p);

  bool decode(Header &p);

  bool decode(TlvsHeader &p);

  bool decode(BindReceiver &p);

  bool decode(BindReceiverResp &p);

  bool decode(BindTransmitter &p);

  bool decode(BindTransmitterResp &p);

  bool decode(BindTransceiver &p);

  bool decode(BindTransceiverResp &p);

  bool decode(BroadcastSm &p);

  bool decode(BroadcastSmResp &p);

  bool decode(CancelBroadcastSm &p);

  bool decode(CancelBroadcastSmResp &p);

  bool decode(CancelSm &p);

  bool decode(CancelSmResp &p);

  bool decode(DataSm &p);

  bool decode(DataSmResp &p);

  bool decode(DeliverSm &p);

  bool decode(DeliverSmResp &p);

  bool decode(EnquireLink &p);

  bool decode(EnquireLinkResp &p);

  bool decode(GenericNack &p);

  bool decode(Outbind &p);

  bool decode(QueryBroadcastSm &p);

  bool decode(QueryBroadcastSmResp &p);

  bool decode(QuerySm &p);

  bool decode(QuerySmResp &p);

  bool decode(ReplaceSm &p);

  bool decode(ReplaceSmResp &p);

  bool decode(SubmitMulti &p);

  bool decode(SubmitMultiResp &p);

  bool decode(SubmitSm &p);

  bool decode(SubmitSmResp &p);

  bool decode(Unbind &p);

  bool decode(UnbindResp &p);
};

} // namespace smpp

#endif // SMPP_DECODER_H
