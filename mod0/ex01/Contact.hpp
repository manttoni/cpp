#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
  std::string first, last, nick, nbr, secret;

public:
  Contact();
  Contact(std::string first, std::string last, std::string nick,
          std::string nbr, std::string secret);
  std::string getFirst() const;
  std::string getLast() const;
  std::string getNick() const;
  std::string getNbr() const;
  std::string getSecret() const;
};

#endif