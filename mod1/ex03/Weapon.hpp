#pragma once
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(void);
		Weapon(const std::string &type);
		const std::string &getType(void);
		void setType(std::string &type);
};
