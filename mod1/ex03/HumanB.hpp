#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(const std::string &name);
		void attack(void);
		void setWeapon(Weapon &weapon);
};
