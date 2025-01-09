#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void)
{
	type = "";
}

Weapon::Weapon(const std::string &type) : type(type) {}

const std::string &Weapon::getType(void)
{
	return type;
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
}
