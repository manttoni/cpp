#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; ++i)
			for (int j = 0; argv[i][j] != '\0'; ++j)
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
	}
	std::cout << "\n";
	return 0;
}