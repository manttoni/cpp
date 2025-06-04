#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

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

		template<typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			size_t d = std::distance(begin, end);
			if (numbers.size() + d > N)
				throw std::runtime_error("Span too long");
			numbers.insert(numbers.end(), begin, end);
		}
};

#endif
