#include "Harl.hpp"
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cerr << "Too many arguments\n";
		return (1);
	}
	std::string level = "DEBUG";
	if (argc == 2)
	{
		level = (std::string) argv[1];
	}

	Harl harl = Harl();
	harl.complain(level);

	return (0);
}