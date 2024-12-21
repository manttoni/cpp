#pragma once
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(void);
		Weapon(const std::string &type);
		std::string &getType(void);
		void setType(const std::string &type);
};
