#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int N = 5;

	std::cout << "Creating a horde of " << N << " zombies." << std::endl;
	Zombie *horde = zombieHorde(N, "zombie in a horde");
	if (!horde)
		return 1;
	for (int i = 0; i < N; ++i)
	{
		std::cout << i << ". ";
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}