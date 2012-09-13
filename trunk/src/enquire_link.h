#ifndef SMPP_ENQUIRE_LINK_H
#define SMPP_ENQUIRE_LINK_H

#include <header.h>

namespace smpp {

class EnquireLink : public Request {
public:
  const static int min_length = 16;

  EnquireLink();

  EnquireLink(const SequenceNumber &sequence_number);

  ~EnquireLink();
};

} // namespace smpp

#endif // SMPP_ENQUIRE_LINK_H
