#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl() {}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!\n\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	for (i = 0; i < 4; ++i)
		if (levels[i] == level)
			break;
	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]\n";
			debug();
			[[fallthrough]];
		case 1:
			std::cout << "[ INFO ]\n";
			info();
			[[fallthrough]];
		case 2:
			std::cout << "[ WARNING ]\n";
			warning();
			[[fallthrough]];
		case 3:
			std::cout << "[ ERROR ]\n";
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}