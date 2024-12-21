#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	private:
		std::string name;
		Weapon weapon;
	public:
		HumanA(const std::string &name, Weapon &weapon);
		void attack(void);
};
