#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) : name("") {}

Zombie::Zombie(std::string name) : name(name) {}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie() {}