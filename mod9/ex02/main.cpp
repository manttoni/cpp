#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <cassert>

size_t numbers_total = 0;
int comparisons;

// -1 = error. Algorithm needs only sort positive integers
static int parse_positive_int(const std::string &arg)
{
	if (arg.find_first_not_of("0123456789") != std::string::npos)
		return -1;
	try
	{
		return stoi(arg);
	}
	catch (std::exception &e)
	{
		return -1;
	}
}

int main(int argc, char **argv)
{
	comparisons = 0;
	if (argc == 1)
		return 1;

	std::vector<int> vec;
	std::deque<int> deq;

	numbers_total = argc - 1;
	for (int i = 1; i < argc; ++i)
	{
		int n = parse_positive_int(argv[i]);
		if (n < 0)
		{
			std::cerr << "Error" << std::endl;
			return 2;
		}
		vec.push_back(n);
		deq.push_back(n);
	}

	//std::cout << "Before: ";
	//print_numbers(vec);
	//std::cout << std::endl;

	merge_insert(vec, 1);

	//std::cout << std::endl;
	//std::cout << "After: ";
	//print_numbers(vec);
	//std::cout << std::endl;

	if (!is_sorted(vec, 1))
	{
		print_numbers(vec);
		std::cout << std::endl;
	}

	assert(is_sorted(vec, 1));

	std::cout << "Comparisons: " << comparisons << std::endl;
	/*
	auto start = std::chrono::high_resolution_clock::now();
	vec = PmergeMe(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto vectorDuration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	start = std::chrono::high_resolution_clock::now();
	deq = PmergeMe(deq);
	end = std::chrono::high_resolution_clock::now();
	auto dequeDuration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	*/


//	std::cout << "[std::vector] Numbers: " << argc - 1 << " Time: " << vectorDuration.count() << " ms" << std::endl;
//	std::cout << "[std::deque]  Numbers: " << argc - 1 << " Time: " << dequeDuration.count() << " ms" << std::endl;

	return 0;
}
