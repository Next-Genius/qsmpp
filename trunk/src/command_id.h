#ifndef SMPP_COMMAND_ID_H
#define SMPP_COMMAND_ID_H

#include <types.h>

namespace smpp {

class CommandId {
  smpp::uint32 value;
  CommandId();
public:
  enum {
    BindReceiver          = 0x00000001, /* bind_receiver command id. */
    BindTransmitter       = 0x00000002, /* bind_transmitter command id. */
    QuerySm               = 0x00000003, /* query_sm command id. */
    SubmitSm              = 0x00000004, /* submit_sm command id. */
    DeliverSm             = 0x00000005, /* deliver_sm command id. */
    Unbind                = 0x00000006, /* unbind command id. */
    ReplaceSm             = 0x00000007, /* replace_sm command id. */
    CancelSm              = 0x00000008, /* cancel_sm command id. */
    BindTransceiver       = 0x00000009, /* bind_transceiver command id. */
    Outbind               = 0x0000000B, /* outbind command id. */
    EnquireLink           = 0x00000015, /* enquire_link command id. */
    SubmitMulti           = 0x00000021, /* submit_multi command id. */
    AlertNotification     = 0x00000102, /* alert_notification command id. */
    DataSm                = 0x00000103, /* data_sm command id. */
    BroadcastSm           = 0x00000111, /* broadcast_sm command id. */
    QueryBroadcastSm      = 0x00000112, /* query_broadcast_sm command id. */
    CancelBroadcastSm     = 0x00000113, /* cancel_broadcast_sm command id. */
    GenericNack           = 0x80000000, /* generic_nack command id. */
    BindReceiverResp      = 0x80000001, /* bind_receiver_resp command id. */
    BindTransmitterResp   = 0x80000002, /* bind_transmitter_resp command id. */
    QuerySmResp           = 0x80000003, /* query_sm_resp command id. */
    SubmitSmResp          = 0x80000004, /* submit_sm_resp command id. */
    DeliverSmResp         = 0x80000005, /* deliver_sm_resp command id. */
    UnbindResp            = 0x80000006, /* unbind_resp command id. */
    ReplaceSmResp         = 0x80000007, /* replace_sm_resp command id. */
    CancelSmResp          = 0x80000008, /* cancel_sm_resp command id. */
    BindTransceiverResp   = 0x80000009, /* bind_transceiver_resp command id. */
    EnquireLinkResp       = 0x80000015, /* enquire_link_resp command id. */
    SubmitMultiResp       = 0x80000021, /* submit_multi_resp command id. */
    DataSmResp            = 0x80000103, /* data_sm command_resp id. */
    BroadcastSmResp       = 0x80000111, /* broadcast_sm_resp command id. */
    QueryBroadcastSmResp  = 0x80000112, /* query_broadcast_sm_resp command id. */
    CancelBroadcastSmResp = 0x80000113  /* cancel_broadcast_sm_resp command id. */
  };

  explicit CommandId(const smpp::uint32 &p) : value(p) {}

  CommandId &operator =(const smpp::uint32 &p) { value = p; return *this; }

  operator smpp::uint32() const { return value; }
};

} // namespace smpp

#endif // SMPP_COMMAND_ID_H
