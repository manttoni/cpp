#include "Array.hpp"
#include <iostream>

template <typename T>
void printArr(Array<T> arr)
{
	std::cout << "len=" << arr.size() << ": ";
	for (size_t i = 0; i < arr.size(); ++i)
	{
		std::cout << arr[i];
		if (i < arr.size() -1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "Create array {4,2}" << std::endl;
	Array<int> ft = Array<int>(2);
	ft[0] = 4;
	ft[1] = 2;
	printArr(ft);

	std::cout << "Copy previous array" << std::endl;
	Array<int> ftcopy = Array<int>(ft);
	printArr(ftcopy);

	std::cout << "Assign new values to copy, then print original" << std::endl;
	ftcopy[0] = 6;
	ftcopy[1] = 9;
	printArr(ft);

	std::cout << "Print new values of the copy" << std::endl;
	printArr(ftcopy);

	std::cout << "Testing default constructor" << std::endl;
	Array<char> carr;
	Array<char> carrcopyas = carr;
	Array<char> carrcopyco = Array<char>(carr);
	printArr(carr);
	printArr(carrcopyas);
	printArr(carrcopyco);

	// std::cout << "Test out of bounds error" << std::endl;
	// std::cout << ft[2] << std::endl;

	return 0;
}