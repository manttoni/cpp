#include "RPN.hpp"

#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>

int calculate(const std::string &expr)
{
	std::stack<int> numbers;
	std::string token;
	std::istringstream ss(expr);
	while (getline(ss, token, ' '))
	{
		if (token.size() > 1 || token.empty())
			throw std::runtime_error("Token not a single char: " + token);
		char c = token[0];
		if (isdigit(static_cast<unsigned char>(c)))
		{
			numbers.push(static_cast<int>(c - '0'));
			continue;
		}
		if (numbers.size() < 2)
			throw std::runtime_error("2 numbers needed for operation");
		int right = numbers.top();
		numbers.pop();
		int left = numbers.top();
		numbers.pop();
		switch (c)
		{
			case '+':
				numbers.push(left + right);
				break;
			case '-':
				numbers.push(left - right);
				break;
			case '*':
				numbers.push(left * right);
				break;
			case '/':
				if (right == 0)
					throw std::runtime_error("Division by zero");
				numbers.push(left / right);
				break;
			default:
				throw std::runtime_error(std::string("Invalid operator: ") + c);
		}
	}
	if (numbers.size() != 1)
		throw std::runtime_error("Stack size not 1");
	return numbers.top();
}
