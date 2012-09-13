#ifndef SMPP_UNBIND_H
#define SMPP_UNBIND_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class Unbind : public Request {
public:
  const static int min_length = 16;

  Unbind();

  Unbind(const SequenceNumber &sequence_number);

  ~Unbind();
};

} // namespace smpp

#endif // SMPP_UNBIND_H
