#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void)
{
	type = "empty";
}

Weapon::Weapon(const std::string &type) : type(type) {}

std::string &Weapon::getType(void)
{
	return type;
}

void Weapon::setType(const std::string &type)
{
	std::cout << "setting weapon to " << type << std::endl;
	this->type = type;
}
