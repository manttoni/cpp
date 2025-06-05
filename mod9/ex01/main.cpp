#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <RPN mathematical expression>" << std::endl;
		return 1;
	}

	try
	{
		std::cout << calculate(argv[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 2;
	}

	return 0;
}
