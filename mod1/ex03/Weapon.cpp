#include "Weapon.hpp"

Weapon::Weapon(std::string &type)
{
	this->type = type;
}

std::string &getType(void) const
{
	return type;
}

void setType(std::string &type)
{
	this->type = type;
}
