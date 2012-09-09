#ifndef QSMPP_CONSTANTS_H
#define QSMPP_CONSTANTS_H

#include <global.h>
#include <QByteArray>
#include <QString>

namespace qsmpp {

typedef QByteArray octetString;
typedef QString CoctetString;

namespace constants {

namespace CommandId {

static const quint32 GENERIC_NACK                 = 0x80000000;
static const quint32 BIND_RECEIVER                = 0x00000001;
static const quint32 BIND_RECEIVER_RESP           = 0x80000001;
static const quint32 BIND_TRANSMITTER             = 0x00000002;
static const quint32 BIND_TRANSMITTER_RESP        = 0x80000002;
static const quint32 QUERY_SM                     = 0x00000003;
static const quint32 QUERY_SM_RESP                = 0x80000003;
static const quint32 SUBMIT_SM                    = 0x00000004;
static const quint32 SUBMIT_SM_RESP               = 0x80000004;
static const quint32 DELIVER_SM                   = 0x00000005;
static const quint32 DELIVER_SM_RESP              = 0x80000005;
static const quint32 UNBIND                       = 0x00000006;
static const quint32 UNBIND_RESP                  = 0x80000006;
static const quint32 REPLACE_SM                   = 0x00000007;
static const quint32 REPLACE_SM_RESP              = 0x80000007;
static const quint32 CANCEL_SM                    = 0x00000008;
static const quint32 CANCEL_SM_RESP               = 0x80000008;
static const quint32 BIND_TRANSCEIVER             = 0x00000009;
static const quint32 BIND_TRANSCEIVER_RESP        = 0x80000009;
static const quint32 OUTBIND                      = 0x0000000B;
static const quint32 ENQUIRE_LINK                 = 0x00000015;
static const quint32 ENQUIRE_LINK_RESP            = 0x80000015;
static const quint32 SUBMIT_MULTI                 = 0x00000021;
static const quint32 SUBMIT_MULTI_RESP            = 0x80000021;
static const quint32 ALERT_NOTIFICATION           = 0x00000102;
static const quint32 DATA_SM                      = 0x00000103;
static const quint32 DATA_SM_RESP                 = 0x80000103;
static const quint32 BROADCAST_SM                 = 0x00000111;
static const quint32 BROADCAST_SM_RESP            = 0x80000111;
static const quint32 QUERY_BROADCAST_SM           = 0x00000112;
static const quint32 QUERY_BROADCAST_SM_RESP      = 0x80000112;
static const quint32 CANCEL_BROADCAST_SM          = 0x00000113;
static const quint32 CANCEL_BROADCAST_SM_RESP     = 0x80000113;

} // namespace CommandId

namespace ErrorCode {

static const quint32 ROK                          = 0x00000000;
static const quint32 RINVMSGLEN                   = 0x00000001;
static const quint32 RINVCMDLEN                   = 0x00000002;
static const quint32 RINVCMDID                    = 0x00000003;
static const quint32 RINVBNDSTS                   = 0x00000004;
static const quint32 RALYBND                      = 0x00000005;
static const quint32 RINVPRTFLG                   = 0x00000006;
static const quint32 RINVREGDLVFLG                = 0x00000007;
static const quint32 RSYSERR                      = 0x00000008;
static const quint32 RINVSRCADR                   = 0x0000000A;
static const quint32 RINVDSTADR                   = 0x0000000B;
static const quint32 RINVMSGID                    = 0x0000000C;
static const quint32 RBINDFAIL                    = 0x0000000D;
static const quint32 RINVPASWD                    = 0x0000000E;
static const quint32 RINVSYSID                    = 0x0000000F;
static const quint32 RCANCELFAIL                  = 0x00000011;
static const quint32 RREPLACEFAIL                 = 0x00000013;
static const quint32 RMSGQFUL                     = 0x00000014;
static const quint32 RINVSERTYP                   = 0x00000015;
static const quint32 RINVNUMDESTS                 = 0x00000033;
static const quint32 RINVDLNAME                   = 0x00000034;
static const quint32 RINVDESTFLAG                 = 0x00000040;
static const quint32 RINVSUBREP                   = 0x00000042;
static const quint32 RINVESMCLASS                 = 0x00000043;
static const quint32 RCNTSUBDL                    = 0x00000044;
static const quint32 RSUBMITFAIL                  = 0x00000045;
static const quint32 RINVSRCTON                   = 0x00000048;
static const quint32 RINVSRCNPI                   = 0x00000049;
static const quint32 RINVDSTTON                   = 0x00000050;
static const quint32 RINVDSTNPI                   = 0x00000051;
static const quint32 RINVSYSTYP                   = 0x00000053;
static const quint32 RINVREPFLAG                  = 0x00000054;
static const quint32 RINVNUMMSGS                  = 0x00000055;
static const quint32 RTHROTTLED                   = 0x00000058;
static const quint32 RINVSCHED                    = 0x00000061;
static const quint32 RINVEXPIRY                   = 0x00000062;
static const quint32 RINVDFTMSGID                 = 0x00000063;
static const quint32 RX_T_APPN                    = 0x00000064;
static const quint32 RX_P_APPN                    = 0x00000065;
static const quint32 RX_R_APPN                    = 0x00000066;
static const quint32 RQUERYFAIL                   = 0x00000067;
static const quint32 RINVTLVSTREAM                = 0x000000C0;
static const quint32 RTLVNOTALLWD                 = 0x000000C1;
static const quint32 RINVTLVLEN                   = 0x000000C2;
static const quint32 RMISSINGTLV                  = 0x000000C3;
static const quint32 RINVTLVVAL                   = 0x000000C4;
static const quint32 RDELIVERYFAILURE             = 0x000000FE;
static const quint32 RUNKNOWNERR                  = 0x000000FF;
static const quint32 RSERTYPUNAUTH                = 0x00000100;
static const quint32 RPROHIBITED                  = 0x00000101;
static const quint32 RSERTYPUNAVAIL               = 0x00000102;
static const quint32 RSERTYPDENIED                = 0x00000103;
static const quint32 RINVDCS                      = 0x00000104;
static const quint32 RINVSRCADDRSUBUNIT           = 0x00000105;
static const quint32 RINVDSTADDRSUBUNIT           = 0x00000106;
static const quint32 RINVBCASTFREQINT             = 0x00000107;
static const quint32 RINVBCASTALIAS_NAME          = 0x00000108;
static const quint32 RINVBCASTAREAFMT             = 0x00000109;
static const quint32 RINVNUMBCAST_AREAS           = 0x0000010A;
static const quint32 RINVBCASTCNTTYPE             = 0x0000010B;
static const quint32 RINVBCASTMSGCLASS            = 0x0000010C;
static const quint32 RBCASTFAIL                   = 0x0000010D;
static const quint32 RBCASTQUERYFAIL              = 0x0000010E;
static const quint32 RBCASTCANCELFAIL             = 0x0000010F;
static const quint32 RINVBCAST_REP                = 0x00000110;
static const quint32 RINVBCASTSRVGRP              = 0x00000111;
static const quint32 RINVBCASTCHANIND             = 0x00000112;
static const quint32 ERRDECSEQNUM                 = 0x00000400;
static const quint32 ERRDECERRSTCODE              = 0x00000401;

} // namespace ErrorCode

namespace TLVtags {

static const quint16 DEST_ADDR_SUBUNIT            = 0x0005;    // GSM
static const quint16 DEST_NETWORK_TYPE            = 0x0006;    // Generic
static const quint16 DEST_BEARER_TYPE             = 0x0007;    // Generic
static const quint16 DEST_TELEMATICS_ID           = 0x0008;    // GSM
static const quint16 DEST_PORT                    = 0x020B;
static const quint16 SOURCE_ADDR_SUBUNIT          = 0x000D;    // GSM
static const quint16 SOURCE_NETWORK_TYPE          = 0x000E;    // Generic
static const quint16 SOURCE_BEARER_TYPE           = 0x000F;    // Generic
static const quint16 SOURCE_TELEMATICS_ID         = 0x0010;    // GSM
static const quint16 QOS_TIME_TO_LIVE             = 0x0017;    // Generic
static const quint16 PAYLOAD_TYPE                 = 0x0019;    // Generic
static const quint16 ADDITIONAL_STATUS_INFO_TEXT  = 0x001D;    // Generic
static const quint16 RECEIPTED_MESSAGE_ID         = 0x001E;    // Generic
static const quint16 MS_MSG_WAIT_FACILITIES       = 0x0030;    // GSM
static const quint16 PRIVACY_INDICATOR            = 0x0201;    // CDMA, TDMA
static const quint16 SOURCE_SUBADDRESS            = 0x0202;    // CDMA, TDMA
static const quint16 DEST_SUBADDRESS              = 0x0203;    // CDMA, TDMA
static const quint16 USER_MESSAGE_REFERENCE       = 0x0204;    // Generic
static const quint16 USER_RESPONSE_CODE           = 0x0205;    // CDMA, TDMA
static const quint16 SOURCE_PORT                  = 0x020A;    // Generic
static const quint16 DESTINATION_PORT             = 0x020B;    // Generic
static const quint16 SAR_MSG_REF_NUM              = 0x020C;    // Generic
static const quint16 LANGUAGE_INDICATOR           = 0x020D;    // CDMA, TDMA
static const quint16 SAR_TOTAL_SEGMENTS           = 0x020E;    // Generic
static const quint16 SAR_SEGMENT_SEQNUM           = 0x020F;    // Generic
static const quint16 SC_INTERFACE_VERSION         = 0x0210;    // Generic
static const quint16 CALLBACK_NUM_PRES_IND        = 0x0302;    // TDMA
static const quint16 CALLBACK_NUM_ATAG            = 0x0303;    // TDMA
static const quint16 NUMBER_OF_MESSAGES           = 0x0304;    // CDMA
static const quint16 CALLBACK_NUM                 = 0x0381;    // CDMA, TDMA, GSM, iDEN
static const quint16 CONGESTION_STATE             = 0x0428;
static const quint16 DPF_RESULT                   = 0x0420;    // Generic
static const quint16 SET_DPF                      = 0x0421;    // Generic
static const quint16 MS_AVAILABILITY_STATUS       = 0x0422;    // Generic
static const quint16 NETWORK_ERROR_CODE           = 0x0423;    // Generic
static const quint16 MESSAGE_PAYLOAD              = 0x0424;    // Generic
static const quint16 DELIVERY_FAILURE_REASON      = 0x0425;    // Generic
static const quint16 MORE_MESSAGES_TO_SEND        = 0x0426;    // GSM
static const quint16 MESSAGE_STATE                = 0x0427;    // Generic
static const quint16 USSD_SERVICE_OP              = 0x0501;    // GSM (USSD)
static const quint16 DISPLAY_TIME                 = 0x1201;    // CDMA, TDMA
static const quint16 SMS_SIGNAL                   = 0x1203;    // TDMA
static const quint16 MS_VALIDITY                  = 0x1204;    // CDMA, TDMA
static const quint16 ALERT_ON_MESSAGE_DELIVERY    = 0x130C;    // CDMA
static const quint16 ITS_REPLY_TYPE               = 0x1380;    // CDMA
static const quint16 ITS_SESSION_INFO             = 0x1383;    // CDMA
static const quint16 BROADCAST_CHANNEL_INDICATOR  = 0x0600;    // GSM
static const quint16 BROADCAST_CONTENT_TYPE       = 0x0601;    // CDMA, TDMA, GSM
static const quint16 BROADCAST_CONTENT_TYPE_INFO  = 0x0602;    // CDMA, TDMA
static const quint16 BROADCAST_MESSAGE_CLASS      = 0x0603;    // GSM
static const quint16 BROADCAST_REP_NUM            = 0x0604;    // GSM
static const quint16 BROADCAST_FREQUENCY_INTERVAL = 0x0605;    // CDMA, TDMA, GSM
static const quint16 BROADCAST_AREA_IDENTIFIER    = 0x0606;    // CDMA, TDMA, GSM
static const quint16 BROADCAST_ERROR_STATUS       = 0x0607;    // CDMA, TDMA, GSM
static const quint16 BROADCAST_AREA_SUCCESS       = 0x0608;    // GSM
static const quint16 BROADCAST_END_TIME           = 0x0609;    // CDMA, TDMA, GSM
static const quint16 BROADCAST_SERVICE_GROUP      = 0x060A;    // CDMA, TDMA
static const quint16 BILLING_IDENTIFICATION       = 0x060B;    // Generic
static const quint16 SOURCE_NETWORK_ID            = 0x060D;    // Generic
static const quint16 DEST_NETWORK_ID              = 0x060E;    // Generic
static const quint16 SOURCE_NODE_ID               = 0x060F;    // Generic
static const quint16 DEST_NODE_ID                 = 0x0610;    // Generic
static const quint16 DEST_ADDR_NP_RESOLUTION      = 0x0611;    // CDMA, TDMA (US Only)
static const quint16 DEST_ADDR_NP_INFORMATION     = 0x0612;    // CDMA, TDMA (US Only)
static const quint16 DEST_ADDR_NP_COUNTRY         = 0x0613;    // CDMA, TDMA (US Only)

} // namespace TLVtags

namespace DestFlag {

static const quint8 UNKNOWN                        = 0x00;
static const quint8 SME_ADDRESS                    = 0x01;
static const quint8 DISTR_LIST_NAME                = 0x02;

} // namespace DestFlag

namespace InterfaceVersion {

static const quint8 SMPP_VER_0_0                   = 0x00;
static const quint8 SMPP_VER_3_3                   = 0x33;
static const quint8 SMPP_VER_3_4                   = 0x34;
static const quint8 SMPP_VER_5_0                   = 0x50;

} // namespace InterfaceVersion

} // namespace constants
} // namespace qsmpp

#endif // QSMPP_CONSTANTS_H
