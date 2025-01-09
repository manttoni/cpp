#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name)
{
	Zombie* zombie = new(std::nothrow) Zombie(name);
	if (!zombie)
		std::cout << "Memory allocation failed" << std::endl;
	return zombie;
}