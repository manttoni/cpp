#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string &name)
{
	this->name = name;
	HumanB::setWeapon(Weapon("empty"));
}

void HumanB::setWeapon(Weapon::Weapon &weapon)
{
	HumanB::setWeapon(weapon);
}

void HumanB::attack(void)
{
	if (weapon.getType() != "empty")
		std::cout << name << " attacks with their " << weapon.getType() << std::endl;
	else
		std::cout << name << " doesn't have a weapon" << std::endl;
}

