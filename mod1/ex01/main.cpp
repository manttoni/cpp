#include "Zombie.hpp"

int main(void)
{
	int N = 100;

	Zombie *horde = zombieHorde(N, "rabdin");
	for (int i = 0; i < N; ++i)
	{
		horde[i].announce();
	}
	delete[] horde;
}