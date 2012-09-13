#ifndef SMPP_OUTBIND_H
#define SMPP_OUTBIND_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class Outbind : public Request {
  SystemId system_id;
  Password password;
public:
  const static int min_length = 18;

  Outbind();

  Outbind(const SequenceNumber &sequence_number,
          const SystemId &system_id,
          const Password &password);

  ~Outbind();

  //
  // Mutating
  //

  void setSystemId(const SystemId &p) {
    int diff = p.length() - system_id.length();
    system_id = p;
    Header::updateLength(diff);
  }

  void setSystemId(const char *p) {
    int diff = strlen(p) - system_id.length();
    system_id = p;
    Header::updateLength(diff);
  }

  void setPassword(const Password &p) {
    int diff = p.length() - password.length();
    password = p;
    Header::updateLength(diff);
  }

  void setPassword(const char *p) {
    int diff = strlen(p) - password.length();
    password = p;
    Header::updateLength(diff);
  }

  //
  // Accessing
  //

  const SystemId &getSystemId() const { return system_id; }

  const Password &getPassword() const { return password; }
};

} // namespace smpp

#endif // SMPP_OUTBIND_H
