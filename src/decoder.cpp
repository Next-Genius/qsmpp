#include <decoder.h>

namespace smpp {

Decoder::Decoder() :
  data(0), pos(0), max_pos(-1), last_error(CommandStatus::ESME_ROK) {

}

Decoder::~Decoder() {

}

void Decoder::setData(const uint8 *data, const int &length) {
  this->data = data;
  max_pos = length - 1;
  pos = 0;
}

void Decoder::clear() {
  this->data = 0;
  max_pos = -1;
  pos = 0;
}

bool Decoder::decode(uint32 &p) {
  const int size_of(sizeof uint32);
  if(pos + size_of > max_pos)
    return false;
  memcpy(&p, &data[pos], size_of);
  p = ntoh32(p);
  pos += size_of;
  return true;
}

bool Decoder::decode(uint16 &p) {
  const int size_of(sizeof uint16);
  if(pos + size_of > max_pos)
    return false;
  memcpy(&p, &data[pos], size_of);
  p = ntoh16(p);
  pos += size_of;
  return true;
}

bool Decoder::decode(uint8 &p) {
  if(pos > max_pos)
    return false;
  memcpy(&p, &data[pos], sizeof uint8);
  pos++;
  return true;
}

bool Decoder::decode(CString &p) {
  int temp_pos(pos);
  while(1) {
    if(temp_pos > max_pos)
      return false;
    if(data[temp_pos++] == '\0')
      break;
  }
  p.clear();
  temp_pos -= pos + 1;
  p.resize(temp_pos);
  for(int i = 0; i < temp_pos; i++)
    p[i] = data[pos++];
  pos++;
  return true;
}

bool Decoder::decode(uint8 *data, const int &length) {
  if((pos + length) > max_pos)
    return false;
  memcpy(data, &data[pos], length);
  pos += length;
  return true;
}

bool Decoder::decode(SmeAddress &p) {
  bool ok(false);
  uint8 ton(0);
  ok = decode(ton);
  if(!ok) {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    return ok;
  }
  uint8 npi(0);
  ok = decode(npi);
  if(!ok) {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    return ok;
  }
  Address address;
  ok = decode(address);
  if(ok) {
    SmeAddress sme_address(Ton(ton), Npi(npi), address);
    p = sme_address;
  } else {
    last_error = CommandStatus::ESME_RINVMSGLEN;
  }
  return ok;
}

bool Decoder::decode(UnsuccessSme &p) {
  bool ok(false);
  SmeAddress sme_address;
  ok = decode(sme_address);
  if(ok) {
    p.setSmeAddress(sme_address);
  } else {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    return ok;
  }
  uint32 error(0);
  ok = decode(error);
  if(ok) {
    p.setError(error);
  } else {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    return ok;
  }
  return ok;
}

bool Decoder::decode(MultiDestinationAddresses &p) {
  //p.add()
  return true;
}

bool Decoder::decode(UnsuccessSmeColl &p) {
  return true;
}

bool Decoder::decode(Header &p) {
  bool ok(false);
  uint32 value(0);
  ok = decode(value);
  if(ok) {
    p.setCommandLength(value);
  } else {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setCommandId(value);
  } else {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setCommandStatus(value);
  } else {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setSequenceNumber(value);
  } else {
    last_error = CommandStatus::ESME_RINVMSGLEN;
  }
  return ok;
}

bool Decoder::decode(TlvsHeader &p) {
  bool ok(false);
  uint16 tag(0);
  uint16 length(0);
  uint8 *value(0);
  while(pos + 1 != p.getCommandLength()) {
    ok = decode(tag);
    if(!ok) {
      last_error = CommandStatus::ESME_RINVCMDLEN;
      return ok;
    }
    ok = decode(length);
    if(!ok) {
      last_error = CommandStatus::ESME_RINVCMDLEN;
      return ok;
    }
    value = new uint8[length];
    ok = decode(value, length);
    if(!ok) {
      delete [] value;
      last_error = CommandStatus::ESME_RINVCMDLEN;
      return ok;
    }
    p.insertArrayTlv(tag, length, value);
    delete [] value;
  }
  ok = true;
  return ok;
}

bool Decoder::decode(BindReceiver &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setSystemId(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setPassword(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setSystemType(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  uint8 value;
  ok = decode(value);
  if(ok) {
    p.setInterfaceVersion(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setAddrTon(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setAddrNpi(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setAddressRange(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
  }
  return ok;
}

bool Decoder::decode(BindReceiverResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SystemId system_id;
  ok = decode(system_id);
  if(ok) {
    p.setSystemId(system_id);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(BindTransmitter &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setSystemId(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setPassword(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setSystemType(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  uint8 value;
  ok = decode(value);
  if(ok) {
    p.setInterfaceVersion(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setAddrTon(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setAddrNpi(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setAddressRange(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
  }
  return ok;
}

bool Decoder::decode(BindTransmitterResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SystemId system_id;
  ok = decode(system_id);
  if(ok) {
    p.setSystemId(system_id);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(BindTransceiver &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setSystemId(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setPassword(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setSystemType(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  uint8 value(0);
  ok = decode(value);
  if(ok) {
    p.setInterfaceVersion(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setAddrTon(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setAddrNpi(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setAddressRange(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
  }
  return ok;
}

bool Decoder::decode(BindTransceiverResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SystemId system_id;
  ok = decode(system_id);
  if(ok) {
    p.setSystemId(system_id);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(BroadcastSm &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setServiceType(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SmeAddress source_addr;
  ok = decode(source_addr);
  if(ok) {
    p.setSourceAddr(source_addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setMessageId(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  uint8 value(0);
  ok = decode(value);
  if(ok) {
    p.setPriorityFlag(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setScheduleDeliveryTime(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setValidityPeriod(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setReplaceIfPresentFlag(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setDataCoding(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setSmDefaultMsgId(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(BroadcastSmResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  MessageId message_id;
  ok = decode(message_id);
  if(ok) {
    p.setMessageId(message_id);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(CancelBroadcastSm &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setServiceType(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setMessageId(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SmeAddress source_addr;
  ok = decode(source_addr);
  if(ok) {
    p.setSourceAddr(source_addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(CancelBroadcastSmResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(CancelSm &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setServiceType(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setMessageId(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SmeAddress addr;
  ok = decode(addr);
  if(ok) {
    p.setSourceAddr(addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(addr);
  if(ok) {
    p.setDestinationAddr(addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
  }
  return ok;
}

bool Decoder::decode(CancelSmResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(DataSm &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setServiceType(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SmeAddress addr;
  ok = decode(addr);
  if(ok) {
    p.setSourceAddr(addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(addr);
  if(ok) {
    p.setDestinationAddr(addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
  }
  uint8 value(0);
  ok = decode(value);
  if(ok) {
    p.setEsmClass(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setRegisteredDelivery(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setDataCoding(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(DataSmResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  MessageId message_id;
  ok = decode(message_id);
  if(ok) {
    p.setMessageId(message_id);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(DeliverSm &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setServiceType(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SmeAddress addr;
  ok = decode(addr);
  if(ok) {
    p.setSourceAddr(addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(addr);
  if(ok) {
    p.setDestinationAddr(addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
  }
  uint8 value(0);
  ok = decode(value);
  if(ok) {
    p.setEsmClass(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setProtocolId(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setPriorityFlag(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setScheduleDeliveryTime(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setValidityPeriod(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setRegisteredDelivery(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setReplaceIfPresentFlag(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setDataCoding(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setSmDefaultMsgId(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(!ok) {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    return ok;
  }
  uint8 *data = new uint8[value];
  ok = decode(data, value);
  if(ok) {
    p.setShortMessage(data, value);
    delete [] data;
  } else {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    delete [] data;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(DeliverSmResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  MessageId message_id;
  ok = decode(message_id);
  if(ok) {
    p.setMessageId(message_id);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(EnquireLink &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(EnquireLinkResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(GenericNack &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(Outbind &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setSystemId(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setPassword(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
  }
  return ok;
}

bool Decoder::decode(QueryBroadcastSm &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  MessageId message_id;
  ok = decode(message_id);
  if(ok) {
    p.setMessageId(message_id);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SmeAddress source_addr;
  ok = decode(source_addr);
  if(ok) {
    p.setSourceAddr(source_addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(QueryBroadcastSmResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  MessageId message_id;
  ok = decode(message_id);
  if(ok) {
    p.setMessageId(message_id);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(QuerySm &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  MessageId message_id;
  ok = decode(message_id);
  if(ok) {
    p.setMessageId(message_id);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SmeAddress source_addr;
  ok = decode(source_addr);
  if(ok) {
    p.setSourceAddr(source_addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(QuerySmResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setMessageId(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setFinalDate(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  uint8 value(0);
  ok = decode(value);
  if(ok) {
    p.setMessageState(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setMessageState(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  return ok;
}

bool Decoder::decode(ReplaceSm &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setMessageId(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SmeAddress addr;
  ok = decode(addr);
  if(ok) {
    p.setSourceAddr(addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setScheduleDeliveryTime(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setValidityPeriod(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  uint8 value(0);
  ok = decode(value);
  if(ok) {
    p.setRegisteredDelivery(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setSmDefaultMsgId(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(!ok) {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    return ok;
  }
  uint8 *data = new uint8[value];
  ok = decode(data, value);
  if(ok) {
    p.setShortMessage(data, value);
    delete [] data;
  } else {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    delete [] data;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(ReplaceSmResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(SubmitMulti &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setServiceType(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SmeAddress addr;
  ok = decode(addr);
  if(ok) {
    p.setSourceAddr(addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  uint8 value(0);
  ok = decode(value);
  if(ok) {
    p.setEsmClass(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setProtocolId(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setPriorityFlag(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setScheduleDeliveryTime(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setValidityPeriod(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setRegisteredDelivery(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setReplaceIfPresentFlag(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setDataCoding(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setSmDefaultMsgId(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(!ok) {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    return ok;
  }
  uint8 *data = new uint8[value];
  ok = decode(data, value);
  if(ok) {
    p.setShortMessage(data, value);
    delete [] data;
  } else {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    delete [] data;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;

}

bool Decoder::decode(SubmitMultiResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  MessageId message_id;
  ok = decode(message_id);
  if(ok) {
    p.setMessageId(message_id);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  UnsuccessSme unsuccess_sme;
  ok = decode(unsuccess_sme);
  if(ok) {
    p.setUnsuccessSme(unsuccess_sme);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(SubmitSm &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  CString c_string;
  ok = decode(c_string);
  if(ok) {
    p.setServiceType(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  SmeAddress addr;
  ok = decode(addr);
  if(ok) {
    p.setSourceAddr(addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(addr);
  if(ok) {
    p.setDestinationAddr(addr);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
  }
  uint8 value(0);
  ok = decode(value);
  if(ok) {
    p.setEsmClass(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setProtocolId(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setPriorityFlag(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setScheduleDeliveryTime(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(c_string);
  if(ok) {
    p.setValidityPeriod(c_string.data());
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setRegisteredDelivery(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setReplaceIfPresentFlag(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setDataCoding(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(ok) {
    p.setSmDefaultMsgId(value);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(value);
  if(!ok) {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    return ok;
  }
  uint8 *data = new uint8[value];
  ok = decode(data, value);
  if(ok) {
    p.setShortMessage(data, value);
    delete [] data;
  } else {
    last_error = CommandStatus::ESME_RINVMSGLEN;
    delete [] data;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(SubmitSmResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok) {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  MessageId message_id;
  ok = decode(message_id);
  if(ok) {
    p.setMessageId(message_id);
  } else {
    last_error = CommandStatus::ESME_RINVCMDLEN;
    return ok;
  }
  ok = decode(*reinterpret_cast<TlvsHeader *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(Unbind &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

bool Decoder::decode(UnbindResp &p) {
  bool ok(false);
  ok = decode(*reinterpret_cast<Header *>(&p));
  if(!ok)
    last_error = CommandStatus::ESME_RINVCMDLEN;
  return ok;
}

} // namespace smpp
