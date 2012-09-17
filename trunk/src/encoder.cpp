#include <encoder.h>

namespace smpp {

Encoder::Encoder() :  data(0), offset(0) {

}

Encoder::~Encoder() {
  reset();
}

void Encoder::reset() {
  if(data) {
    delete [] data;
    data = 0;
    offset = 0;
  }
}

void Encoder::reset(const uint32 &length) {
  reset();
  data = new uint8[length];
}

Encoder &Encoder::operator +=(const uint32 &p) {
  ::memcpy(&data[offset], &p, sizeof p);
  offset += sizeof p;
  return *this;
}

Encoder &Encoder::operator +=(const uint16 &p) {
  ::memcpy(&data[offset], &p, sizeof p);
  offset += sizeof p;
  return *this;
}

Encoder &Encoder::operator +=(const uint8 &p) {
  data[offset++] = p;
  return *this;
}

Encoder &Encoder::operator +=(const CString &p) {
  std::copy(p.begin(), p.end(), data + offset);
  offset += p.length() + 1;
  data[offset - 1] = 0;
  return *this;
}

Encoder &Encoder::operator +=(const ShortMessage &p) {
  data[offset++] = p.length();
  std::copy(p.begin(), p.end(), &data[offset]);
  offset += p.length();
  return *this;
}

Encoder &Encoder::operator +=(const SmeAddress &p) {
  *this += p.getTon();
  *this += p.getNpi();
  *this += p.getAddress();
  return *this;
}

Encoder &Encoder::operator +=(const MultiDestinationAddresses &p) {
  *this += p.size();
  CopySubmitMultiAddresses i(*this);
  std::for_each(p.getList().begin(), p.getList().end(), i);
  return *this;
}

Encoder &Encoder::operator +=(const UnsuccessSmeColl &p) {
  *this += p.size();
  CopyUnsuccessSmeColl i(*this);
  std::for_each(p.getList().begin(), p.getList().end(), i);
  return *this;
}

void Encoder::addHeader(const Header &p) {
  *this += hton32(p.getCommandLength());
  *this += hton32(p.getCommandId());
  *this += hton32(p.getCommandStatus());
  *this += hton32(p.getSequenceNumber());
}

void Encoder::addTlv(const Tlv &p) {
  *this += hton16(p.getTag());
  *this += hton16(p.getLength());
  addOctetArray(p.getLength(), p.getValue());
}

void Encoder::addTlvs(const TlvList &p) {
  for(TlvList::const_iterator it = p.begin(); it != p.end(); it++)
    addTlv(*(*it));
}

Encoder &Encoder::operator +=(const BindReceiver &p) {
  addHeader(p); // insert the header first
  *this += p.getSystemId();
  *this += p.getPassword();
  *this += p.getSystemType();
  *this += p.getInterfaceVersion();
  *this += p.getAddrTon();
  *this += p.getAddrNpi();
  *this += p.getAddressRange();
  return *this;
}

Encoder &Encoder::operator +=(const BindReceiverResp &p) {
  addHeader(p);
  *this += p.getSystemId();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const BindTransmitter &p) {
  addHeader(p);
  *this += p.getSystemId();
  *this += p.getPassword();
  *this += p.getSystemType();
  *this += p.getInterfaceVersion();
  *this += p.getAddrTon();
  *this += p.getAddrNpi();
  *this += p.getAddressRange();
  return *this;
}

Encoder &Encoder::operator +=(const BindTransmitterResp &p) {
  addHeader(p);
  *this += p.getSystemId();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const BindTransceiver &p) {
  addHeader(p); // insert the header first
  *this += p.getSystemId();
  *this += p.getPassword();
  *this += p.getSystemType();
  *this += p.getInterfaceVersion();
  *this += p.getAddrTon();
  *this += p.getAddrNpi();
  *this += p.getAddressRange();
  return *this;
}

Encoder &Encoder::operator +=(const BindTransceiverResp &p) {
  addHeader(p);
  *this += p.getSystemId();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const BroadcastSm &p) {
  addHeader(p);
  *this += p.getServiceType();
  *this += p.getSourceAddr();
  *this += p.getMessageId();
  *this += p.getPriorityFlag();
  *this += p.getScheduleDeliveryTime();
  *this += p.getValidityPeriod();
  *this += p.getReplaceIfPresentFlag();
  *this += p.getDataCoding();
  *this += p.getSmDefaultMsgId();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const BroadcastSmResp &p) {
  addHeader(p);
  *this += p.getMessageId();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const CancelBroadcastSm &p) {
  addHeader(p);
  *this += p.getServiceType();
  *this += p.getMessageId();
  *this += p.getSourceAddr();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const CancelBroadcastSmResp &p) {
  addHeader(p);
  return *this;
}

Encoder &Encoder::operator +=(const CancelSm &p) {
  addHeader(p);
  *this += p.getServiceType();
  *this += p.getMessageId();
  *this += p.getSourceAddr();
  *this += p.getDestinationAddr();
  return *this;
}

Encoder &Encoder::operator +=(const CancelSmResp &p) {
  addHeader(p);
  return *this;
}

Encoder &Encoder::operator +=(const DataSm &p) {
  addHeader(p);
  *this += p.getServiceType();
  *this += p.getSourceAddr();
  *this += p.getDestinationAddr();
  *this += p.getEsmClass();
  *this += p.getRegisteredDelivery();
  *this += p.getDataCoding();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const DataSmResp &p) {
  addHeader(p);
  *this += p.getMessageId();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const DeliverSm &p) {
  addHeader(p);
  *this += p.getServiceType();
  *this += p.getSourceAddr();
  *this += p.getDestinationAddr();
  *this += p.getEsmClass();
  *this += p.getProtocolId();
  *this += p.getPriorityFlag();
  *this += p.getScheduleDeliveryTime();
  *this += p.getValidityPeriod();
  *this += p.getRegisteredDelivery();
  *this += p.getReplaceIfPresentFlag();
  *this += p.getDataCoding();
  *this += p.getSmDefaultMsgId();
  *this += p.getShortMessage();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const DeliverSmResp &p) {
  addHeader(p);
  *this += p.getMessageId();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const EnquireLink &p) {
  addHeader(p);
  return *this;
}

Encoder &Encoder::operator +=(const EnquireLinkResp &p) {
  reset(p.getCommandLength());
  addHeader(p);
  return *this;
}

Encoder &Encoder::operator +=(const GenericNack &p) {
  addHeader(p);
  return *this;
}

Encoder &Encoder::operator +=(const Outbind &p) {
  addHeader(p);
  *this += p.getSystemId();
  *this += p.getPassword();
  return *this;
}

Encoder &Encoder::operator +=(const QueryBroadcastSm &p) {
  addHeader(p);
  *this += p.getMessageId();
  *this += p.getSourceAddr();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const QueryBroadcastSmResp &p) {
  addHeader(p);
  *this += p.getMessageId();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const QuerySm &p) {
  addHeader(p);
  *this += p.getMessageId();
  *this += p.getSourceAddr();
  return *this;
}

Encoder &Encoder::operator +=(const QuerySmResp &p) {
  addHeader(p);
  *this += p.getMessageId();
  *this += p.getFinalDate();
  *this += p.getMessageState();
  *this += p.getErrorCode();
  return *this;
}

Encoder &Encoder::operator +=(const ReplaceSm &p) {
  addHeader(p);
  *this += p.getMessageId();
  *this += p.getSourceAddr();
  *this += p.getScheduleDeliveryTime();
  *this += p.getValidityPeriod();
  *this += p.getRegisteredDelivery();
  *this += p.getSmDefaultMsgId();
  *this += p.getShortMessage();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const ReplaceSmResp &p) {
  addHeader(p);
  return *this;
}

Encoder &Encoder::operator +=(const SubmitMulti &p) {
  addHeader(p);
  *this += p.getServiceType();
  *this += p.getSourceAddr();
  *this += p.getEsmClass();
  *this += p.getProtocolId();
  *this += p.getPriorityFlag();
  *this += p.getScheduleDeliveryTime();
  *this += p.getValidityPeriod();
  *this += p.getRegisteredDelivery();
  *this += p.getReplaceIfPresentFlag();
  *this += p.getDataCoding();
  *this += p.getSmDefaultMsgId();
  *this += p.getShortMessage();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const SubmitMultiResp &p) {
  addHeader(p);
  *this += p.getMessageId();
  *this += p.getUnsuccessSme();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const SubmitSm &p) {
  addHeader(p);
  *this += p.getServiceType();
  *this += p.getSourceAddr();
  *this += p.getDestinationAddr();
  *this += p.getEsmClass();
  *this += p.getProtocolId();
  *this += p.getPriorityFlag();
  *this += p.getScheduleDeliveryTime();
  *this += p.getValidityPeriod();
  *this += p.getRegisteredDelivery();
  *this += p.getReplaceIfPresentFlag();
  *this += p.getDataCoding();
  *this += p.getSmDefaultMsgId();
  *this += p.getShortMessage();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const SubmitSmResp &p) {
  addHeader(p);
  *this += p.getMessageId();
  addTlvs(p.getTlvList());
  return *this;
}

Encoder &Encoder::operator +=(const Unbind &p) {
  addHeader(p);
  return *this;
}

Encoder &Encoder::operator +=(const UnbindResp &p) {
  addHeader(p);
  return *this;
}

Encoder &Encoder::addOctetArray(const uint32 &length, const uint8 *array) {
  std::copy(array, array + length, data + offset);
  offset += length;
  return *this;
}

} // namespace smpp
