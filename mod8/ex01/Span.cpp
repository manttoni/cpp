#include "Span.hpp"
#include <algorithm>
#include <vector>
#include <limits>

Span::Span() : N(0) {}
Span::~Span() {}
Span::Span(const Span &other) : N(other.N), numbers(other.numbers) {}
Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		numbers = other.numbers;
	}
	return *this;
}
Span::Span(const unsigned int N) : N(N) {}

void Span::addNumber(const int number)
{
	if (numbers.size() >= N)
		throw std::runtime_error("Span is full");
	numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("No span can be found");

	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("No span can be found");

	int min = *std::min_element(numbers.begin(), numbers.end());
	int max = *std::max_element(numbers.begin(), numbers.end());
	return max - min;
}
