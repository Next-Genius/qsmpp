#ifndef SMPP_ENCODER_H
#define SMPP_ENCODER_H

#include <bind_receiver.h>
#include <bind_receiver_resp.h>
#include <bind_transmitter.h>
#include <bind_transmitter_resp.h>

namespace smpp {

class Encoder {
  uint8* data;
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

  Encoder &operator +=(const BindReceiver &p);

  Encoder &operator +=(const BindReceiverResp &p);

  Encoder &operator +=(const BindTransmitter &p);

  Encoder &operator +=(const BindTransmitterResp &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &operator +=(const  &p);

  Encoder &addOctetArray(const uint32 &length, const uint8 *array);

  const uint8 *get() const { return data; }

};

} // namespace smpp

#endif // SMPP_ENCODER_H
