#include "Zombie.hpp"

int main(void)
{
	randomChump("rabdin");
	Zombie* newz = newZombie("newz");
	newz->announce();
}