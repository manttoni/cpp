#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : name(name)
{
	this->name = name;
	//HumanB::setWeapon(Weapon("empty"));
}

HumanB::HumanB(const std::string &name, const Weapon &weapon) : name(name), weapon(weapon)
{
	this->name = name;
	HumanB::setWeapon(Weapon("empty"));
}

void HumanB::setWeapon(const Weapon &weapon)
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

