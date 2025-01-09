#include "Zombie.hpp"

int main(void)
{
	randomChump("randomChump");
	Zombie* newz = newZombie("newZombie");
	if (!newz)
		return 1;
	newz->announce();

	delete newz;
	return 0;
}
