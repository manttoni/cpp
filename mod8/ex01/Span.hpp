#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	private:
		unsigned int N;
		std::vector<int> numbers;
	public:
		// canonical
		Span();
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		// other constructors
		Span(const unsigned int N);

		// member functions
		void addNumber(const int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif
