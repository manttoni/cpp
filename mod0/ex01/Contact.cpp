#include "Contact.hpp"

Contact::Contact() 
    : first(""), last(""), nick(""), nbr(""), secret("") 
{}

Contact::Contact(std::string first, std::string last, std::string nick, std::string nbr, std::string secret)
{
	this->first = first;
	this->last = last;
	this->nick = nick;
	this->nbr = nbr;
	this->secret = secret;
}

std::string Contact::getFirst() const
{
	return first;
}
std::string Contact::getLast() const
{
	return last;
}
std::string Contact::getNick() const
{
	return nick;
}
std::string Contact::getNbr() const
{
	return nbr;
}
std::string Contact::getSecret() const
{
	return secret;
}