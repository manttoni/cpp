#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cassert>
#include <vector>
#include <deque>

extern int comparisons;

int get_highest(auto it, size_t element_size);
void merge_insert_vector(std::vector<int> &elements, const size_t element_size);
void merge_insert_deque(std::deque<int> &elements, const size_t element_size);

// print one element
template <typename Iterator>
void print_element(Iterator it, const size_t element_size)
{
	std::cout << "[";
	for (size_t i = 0; i < element_size; ++i)
	{
		std::cout << *it;
		if (i != element_size - 1)
			std::cout << " ";
		it++;
	}
	std::cout << "]";
}

// print whole array and split them into elements
template <typename T>
void print_elements(const T &elements, const size_t element_size)
{
	std::cout << "{size: " << elements.size() << "} ";
	if (element_size == 0)
	{
		std::cout << std::endl;
		return;
	}
	size_t i;
	for (i = 0; i + element_size <= elements.size(); i += element_size)
	{
		print_element(elements.begin() + i, element_size);
		std::cout << " ";
	}
	for (; i < elements.size(); ++i)
		std::cout << elements[i] << " ";
	std::cout << std::endl;
}

// print whole array as one element
template <typename T>
void print_numbers(const T &numbers)
{
	print_element(numbers.begin(), numbers.size());
}

// find index for element to be inserted into using binary search
template <typename T>
size_t search_lower(const T &main_chain, size_t end, const auto element, const size_t element_size)
{
	auto main_begin = main_chain.begin();
	int ele_value = get_highest(element, element_size);
	size_t begin = 0;
	if (ele_value <= get_highest(main_begin, element_size))
	{
		return 0;
	}
	if (ele_value >= get_highest(main_begin, main_chain.size()))
	{
		return main_chain.size() / element_size;
	}
	begin++;
	while (begin < end)
	{
		comparisons++;
		size_t middle = begin + (end - begin) / 2;
		int mid_value = get_highest(main_begin + middle * element_size, element_size);
		if (ele_value <= mid_value)
		{
			end = middle;
		}
		else
		{
			begin = middle + 1;
		}
	}
	return begin;
}

// return true if every element is sorted, counting the highest/rightmost value only
template <typename T>
bool is_sorted(const T elements, const size_t element_size)
{
	size_t element_count = elements.size() / element_size;
	for (size_t i = 0; i < element_count - 1; i += 1)
	{
		auto curr = elements.begin() + i * element_size;
		auto next = elements.begin() + (i + 1) * element_size;
		int currhigh = get_highest(curr, element_size);
		int nexthigh = get_highest(next, element_size);
		if (currhigh > nexthigh)
			return false;
	}
	return true;
}

// swap adjacent elements to sort. left ones index % 2 == 0
template <typename T>
void swap_pairs(T &elements, const size_t element_size)
{
	// check if can form 2 elements
	if (element_size * 2 > elements.size())
		return;

	size_t element_count = elements.size() / element_size;

	// swap elements to sort
	for (size_t i = 0; i + 1 < element_count; i += 2)
	{
		comparisons++;
		auto left_begin = elements.begin() + i * element_size;
		auto right_begin = left_begin + element_size;

		if (get_highest(left_begin, element_size) <= get_highest(right_begin, element_size))
		{
			continue;
		}

		std::swap_ranges(left_begin, left_begin + element_size, right_begin);
	}
}

#endif
