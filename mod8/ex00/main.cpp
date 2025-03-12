#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int> vec = {1,2,3,4,5};
	try
	{
		std::cout << easyfind(vec, 1) << std::endl;
		std::cout << easyfind(vec, 2) << std::endl;
		std::cout << easyfind(vec, 3) << std::endl;
		std::cout << easyfind(vec, 4) << std::endl;
		std::cout << easyfind(vec, 5) << std::endl;
		std::cout << easyfind(vec, 6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}