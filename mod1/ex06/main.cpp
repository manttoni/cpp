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
	if (argc == 1)
	{
		std::cerr << "Please give a level (DEBUG, INFO, WARNING, ERROR)" << std::endl;
		return (2);
	}

	Harl harl = Harl();
	harl.complain(argv[1]);

	return (0);
}