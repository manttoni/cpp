#include "Span.hpp"
#include <iostream>
#include <random>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << argv[0] << " <N>" << std::endl;
		return 1;
	}
	const std::string input = argv[1];

	if (input.find_first_not_of("1234567890") != std::string::npos)
	{
		std::cout << "Invalid input" << std::endl;
		return 4;
	}

	unsigned long long N_long;
	try
	{
		N_long = std::stoull(input);
	}
	catch(std::exception &e)
	{
		std::cout << "Invalid input" << std::endl;
		return 2;
	}

	if (N_long > std::numeric_limits<unsigned int>::max())
	{
		std::cout << "Input too large" << std::endl;
		return 3;
	}
	unsigned int N = static_cast<unsigned int>(N_long);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

	Span s(N);

	std::cout << "Populating span\r" << std::flush;
	for (unsigned int i = 0; i < N; ++i)
		s.addNumber(dist(gen));
	std::cout << "Span populated \r" << std::flush;

	try
	{
		std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "Longest span: " << s.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
