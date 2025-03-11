#include "iter.hpp"
#include <iostream>
#include <cstring>

void incr(int &i)
{
	i += 1;
}

void megaphone(std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
		std::cout << static_cast<char>(std::toupper(str[i]));
	std::cout << "\n";
}

int main(void)
{
	std::cout << "Create array of ints, 0,1,2,3,4 and iterate them with incr" << std::endl;
	int arr[5];
	for (int i = 0; i < 5; ++i)
	{
		arr[i] = i;
	}
	::iter(arr, 5, &incr);
	for (int i = 0; i < 5; ++i)
		std::cout << arr[i] << std::endl;
	
	std::cout << "Create array of strings, and iterate them with megaphone" << std::endl;
	std::string strs[5];
	strs[0] = "Hello world!";
	strs[1] = "Iteration";
	strs[2] = "duckDUCK123";
	strs[3] = "c4td0g";
	strs[4] = "42";
	::iter(strs, 5, &megaphone);
	
	return 0;
}