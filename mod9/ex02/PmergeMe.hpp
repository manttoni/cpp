#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>

extern size_t numbers_total;
extern int comparisons;

// print one element
void print_element(auto it, size_t element_size)
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
void print_elements(const T &elements, size_t element_size)
{
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

template <typename T>
int get_highest(typename T::iterator it, size_t element_size)
{
	return it[element_size - 1];
}

// find the lower_bound index for element in main_elements
template <typename T>
size_t search_lower(typename T::iterator main_begin, size_t search_max, int ele_value, size_t element_size)
{
	size_t begin = 0;
	size_t end = search_max;
	while (begin < end)
	{
		comparisons++;
		size_t middle = begin + (end - begin) / 2;
		int mid_value = get_highest<T>(main_begin + middle * element_size, element_size);
		if (ele_value <= mid_value)
		{
			std::cout << ele_value << " <= " << mid_value << std::endl;
			end = middle;
		}
		else
		{
			std::cout << ele_value << " > " << mid_value << std::endl;
			begin = middle + 1;
		}
	}
	return begin;
}

template <typename T>
bool is_sorted(T elements, size_t element_size)
{
	size_t element_count = elements.size() / element_size;
	print_elements(elements, element_size);
	for (size_t i = 0; i < element_count - 1; i += element_size)
	{
		auto curr = elements.begin() + i * element_size;
		auto next = elements.begin() + (i + 1) * element_size;
		if (get_highest<T>(curr, element_size) > get_highest<T>(next, element_size))
		{
			std::cout << " is not sorted at " << i << std::endl;
			return false;
		}
	}
	std::cout << " is sorted" << std::endl;
	return true;
}

std::vector<size_t> jacobstahl(const int n)
{
	std::vector<size_t> jacob = {0, 1};
	while (true)
	{
		int next = jacob.back() + jacob[jacob.size() - 2] * 2;
		if (next > n)
			break;
		jacob.push_back(next);
	}
	return jacob;
}

template <typename T>
void merge_insert(T &elements, size_t element_size)
{
	if (is_sorted(elements, element_size))
		return;
	size_t element_count = elements.size() / element_size;

	// check if can form 2 elements
	if (element_size * 2 > elements.size())
	{
		std::cout << "Can't swap" << std::endl;
		return;
	}

	std::cout << "Doing swaps" << std::endl;

	// swap elements to sort
	for (size_t i = 0; i + 1 < element_count; i += 2)
	{
		comparisons++;
		auto left_begin = elements.begin() + i * element_size;
		auto right_begin = left_begin + element_size;

		if (get_highest<T>(left_begin, element_size) <= get_highest<T>(right_begin, element_size))
		{
			std::cout << "No swap this time" << std::endl;
			continue;
		}

		print_element(left_begin, element_size);
		std::cout << " <=> ";
		print_element(right_begin, element_size);
		std::cout << std::endl;

		std::swap_ranges(left_begin, left_begin + element_size, right_begin);
	}

	// go deeper
	merge_insert(elements, element_size * 2);

	// if elements are sorted, no need to do insert
	if (is_sorted(elements, element_size))
		return;

	// start insert phase
	// main is going to be already sorted
	// pend is not sorted
	// leftovers are ignored but saved for later
	T main_elements, pend_elements, leftovers;
	for (size_t i = 0; i < element_count; ++i)
	{
		// get element iterator
		auto element_it = elements.begin() + i * element_size;

		// first element and all odds are main
		if (i == 0 || i % 2 == 1)
		{
			main_elements.insert(main_elements.end(), element_it, element_it + element_size);
			continue;
		}

		// rest are pend
		pend_elements.insert(pend_elements.begin(), element_it, element_it + element_size);
	}

	// save leftovers
	for (size_t i = element_count * element_size; i < elements.size(); ++i)
		leftovers.push_back(elements[i]);

	// label main to keep track of original main chain
	// when inserting from pend to main, add a -1 in that spot
	T labels;
	labels.push_back(-1);
	for (size_t i = 0; i < main_elements.size() / element_size; ++i)
		labels.push_back(i);

	// temporary for testing
	const std::vector<size_t> jacobstahl_order = {3,2,5,4,11,10,9,8,7,6};

	// use Jacobstahl magic numbers to insert pend elements in that order
	for (size_t i = 0; i < pend_elements.size() / element_size; ++i)
	{
		// current magic number
		int jacob = jacobstahl_order[i];

		// index of pend element to be inserted
		size_t pend_i = jacob - 2;

		// index of main element bound to pend element. pend_element <= main element
		// a0 -> a1 -> a2 -> a3 ...
		// b0    b1    b2    b3 ...
		// b0 is -1 in labels
		// first magic number is 3 so a3 and b3(pend_i) are bound

		// find all inserted pend elements up to jacob to find bound element of pend_i
		size_t search_max = 0;
		while (labels[search_max] < jacob - 1)
			search_max++;

		std::cout << "Magic number: " << jacob << std::endl;
		std::cout << "pend_i: " << pend_i << std::endl;
		std::cout << "search_max: " << search_max << std::endl;
		std::cout << "Main elements: ";
		print_elements(main_elements, element_size);
		std::cout << "Pend elements: ";
		print_elements(pend_elements, element_size);
		std::cout << "Leftovers: ";
		print_elements(leftovers, leftovers.size());
		std::cout << "Labels: ";
		print_elements(labels, labels.size());

		// binary search in area 0, search_max
		// insert pend_elements[pend_i] there and insert -1 label to corresponding place
		auto src_begin = pend_elements.begin() + pend_i * element_size;
		auto src_end = src_begin + element_size;
		int pend_val = get_highest<T>(src_begin, element_size);
		size_t dst_i = search_lower<T>(main_elements.begin(), search_max, pend_val, element_size);
		main_elements.insert(main_elements.begin() + dst_i * element_size, src_begin, src_end);
		labels.insert(labels.begin() + dst_i, -1);
	}

	// replace elements with the sorted main_elements
	elements = main_elements;
	elements.insert(elements.end(), leftovers.begin(), leftovers.end());
}

#endif
