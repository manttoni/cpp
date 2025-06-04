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

	unsigned int N;
	try
	{
		N = std::stoul(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cout << "Invalid input" << std::endl;
		return 2;
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

	Span s = Span(N);
	for (unsigned int i = 0; i < N; ++i)
		s.addNumber(dist(gen));

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
