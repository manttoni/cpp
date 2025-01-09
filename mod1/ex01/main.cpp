#include "Zombie.hpp"

int main(void)
{
	int N = 5;

	Zombie *horde = zombieHorde(N, "zombie in a horde");
	if (!horde)
		return 1;
	for (int i = 0; i < N; ++i)
		horde[i].announce();
	delete[] horde;
	return 0;
}