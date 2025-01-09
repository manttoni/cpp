#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde = new(std::nothrow) Zombie[N];
	if (!horde)
		std::cout << "Memory allocation failed" << std::endl;
	else
		for (int i = 0; i < N; ++i)
			horde[i].setname(name);
	return horde;
}