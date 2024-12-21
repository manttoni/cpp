#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		std::string name;
		Weapon weapon;
	public:
		HumanB(const std::string &name);
		HumanB(const std::string &name, const Weapon &weapon);
		void attack(void);
		void setWeapon(const Weapon &weapon);
};
