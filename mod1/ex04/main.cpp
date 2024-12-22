#include <fstream>
#include <string>
#include <iostream>

static void ft_replace(std::string &line, std::string &to_replace, std::string &replacement)
{
	size_t i = line.find(to_replace);
	while (i != std::string::npos)
	{
		line.erase(i, to_replace.length());
		line.insert(i, replacement);
		i = line.find(to_replace, i + replacement.length());
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong amount of arguments. Wanted <filename> <to replace> <replacement>" << std::endl;
		return (1);
	}

	std::ifstream original_file(argv[1]);
	std::ofstream replace_file(std::string(argv[1]) + ".replace");

	std::string line;
	std::string to_replace = (std::string)argv[2];
	std::string replacement = (std::string)argv[3];

	while (getline(original_file, line))
	{
		ft_replace(line, to_replace, replacement);
		replace_file << line << std::endl;
	}
	original_file.close();
	replace_file.close();
	return (0);
}