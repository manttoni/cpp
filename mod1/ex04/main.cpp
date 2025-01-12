#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

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
		std::cout << "Wrong amount of arguments. Wanted <filename> <to_replace> <replacement>" << std::endl;
		return (1);
	}

	if (std::string(argv[2]).empty())
	{
		std::cout << "to_replace can't be empty." << std::endl;
		return (2);
	}

	std::ifstream original_file(argv[1]);
	if (!original_file.is_open())
	{
		std::cerr << "Error opening file: " << argv[1] << std::endl;
		return (3);
	}

	std::ofstream replace_file(std::string(argv[1]) + ".replace");
	if (!replace_file.is_open())
	{
		std::cerr << "Error creating file: " << argv[1] << ".replace" << std::endl;
		original_file.close();
		return (4);
	}

	std::string to_replace = (std::string)argv[2];
	std::string replacement = (std::string)argv[3];
	std::stringstream s;
	s << original_file.rdbuf();
	std::string text = s.str();

	ft_replace(text, to_replace, replacement);
	replace_file << text;

	original_file.close();
	replace_file.close();
	
	return (0);
}
