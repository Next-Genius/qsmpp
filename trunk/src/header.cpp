#include <header.h>

namespace smpp {

Header::Header(const CommandLength &command_length,
               const CommandId &command_id,
               const CommandStatus &command_status,
               const SequenceNumber &sequence_number) :
  command_length(command_length),
  command_id(command_id),
  command_status(command_status),
  sequence_number(sequence_number) {

}

Header::~Header() {

}

void Header::insertAfterTlv(const Tlv *tlv, uint16 tag) {
  TlvList::reverse_iterator i;
  i = std::find_if(tlvs_.list_.rbegin(),
                   tlvs_.list_.rend(),
                   Tlv::CompareTag(tag));
//  if(i == tlvs_.list_.rend())
//    throw Smpp::Error("Missing mandatory TLV");
  tlvs_.list_.insert(i.base(), tlv);
  updateLength(tlv->getLength() + 4);
}

void Header::insertBeforeTlv(const Tlv *tlv, uint16 tag) {
  TlvList::iterator i;
  i = std::find_if(tlvs_.list_.begin(),
                   tlvs_.list_.end(),
                   Tlv::CompareTag(tag));
  //if(i == tlvs_.list_.end())
  //    throw Smpp::Error("Missing mandatory TLV");
  tlvs_.list_.insert(i, tlv);
  updateLength(tlv->getLength() + 4);
}

Request::Request(const CommandLength &command_length,
                 const CommandId &command_id,
                 const SequenceNumber &sequence_number) :
  Header(command_length, command_id, CommandStatus::ESME_ROK, sequence_number) {

}

Response::Response(const CommandLength &command_length,
                   const CommandId &command_id,
                   const CommandStatus &command_status,
                   const SequenceNumber &sequence_number) :
  Header(command_length, command_id, command_status, sequence_number) {

}

} // namespace smpp
