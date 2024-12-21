#include "Weapon.hpp"

Weapon::Weapon(void)
{
	type = "empty";
}

Weapon::Weapon(const std::string &type) : type(type)
{
	this->type = type;
}

const std::string &Weapon::getType(void)
{
	return type;
}

void Weapon::setType(std::string &type)
{
	this->type = type;
}
