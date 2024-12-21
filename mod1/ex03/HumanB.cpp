#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : name(name), weapon(nullptr) {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void)
{
	if (weapon != nullptr)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " doesn't have a weapon" << std::endl;
}

