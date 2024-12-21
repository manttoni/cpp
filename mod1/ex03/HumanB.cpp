#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : name(name) {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
}

void HumanB::attack(void)
{
	if (weapon.getType() != "empty")
		std::cout << name << " attacks with their " << weapon.getType() << std::endl;
	else
		std::cout << name << " doesn't have a weapon" << std::endl;
}

