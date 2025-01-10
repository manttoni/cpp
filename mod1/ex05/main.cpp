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
	Harl harl = Harl();
	if (argc == 2)
		harl.complain(std::string(argv[1]));
	else
	{
		std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		for (int i = 0; i < 15; ++i)
			harl.complain(levels[i%4]);
	}

	return (0);
}