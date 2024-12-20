#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
	name = "zombie";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setname(std::string name)
{
	this->name = name;
}