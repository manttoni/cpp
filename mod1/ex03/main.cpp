#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon axe = Weapon("axe");
	HumanA humana = HumanA("Rabdin", axe);
	HumanB humanb = HumanB("Helron");
	humana.attack();
	humanb.attack();
	return 0;
}
