#ifndef SMPP_GENERIC_NACK_H
#define SMPP_GENERIC_NACK_H

#include <header.h>

namespace smpp {

class GenericNack : public Header {
public:
  const static int min_length = 16;

  GenericNack();

  GenericNack(const CommandStatus &command_status,
              const SequenceNumber &sequence_number);

  ~GenericNack();
};

} // namespace smpp

#endif // SMPP_GENERIC_NACK_H
