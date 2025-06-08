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
size_t search_lower(T &main_elements, auto element, size_t element_size)
{
	int ele_value = get_highest<T>(element, element_size);
	size_t elements_count = main_elements.size() / element_size;
	if (ele_value >= main_elements.back())
		return elements_count;
	size_t begin = 0;
	size_t end = elements_count - 1;
	while (begin < end)
	{
		comparisons++;
		size_t middle = begin + (end - begin) / 2;
		int mid_value = get_highest<T>(main_elements.begin() + middle * element_size, element_size);
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
bool is_sorted(T elements)
{
	for (size_t i = 0; i < elements.size() - 1; ++i)
	{
		if (elements[i] > elements[i + 1])
			return false;
	}
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
void insert_pending(T &main_elements, T &pend_elements, size_t element_size)
{
	if (pend_elements.empty())
		return;

	std::cout << "------------" << std::endl;
	std::cout << "Comparisons: " << comparisons << std::endl;
	std::cout << "Main elements: ";
	print_elements(main_elements, element_size);
	std::cout << "Pend elements: ";
	print_elements(pend_elements, element_size);

	std::vector<size_t> jacob = jacobstahl(pend_elements.size());

	size_t pend_elements_count = pend_elements.size() / element_size;
	size_t jacob_index = 0;
	for (; jacob_index < pend_elements_count - 1; ++jacob_index)
	{
		size_t jacob_value = jacob[jacob_index];
		if (jacob_value > pend_elements_count - 1)
		{
			jacob_index--;
			break;
		}
	}

	std::cout << "Jacob index: " << jacob_index << std::endl;
	auto pend_begin = pend_elements.begin() + jacob_index * element_size;
	size_t insert_id = search_lower(main_elements, pend_begin, element_size);
	auto insert_it = main_elements.begin() + insert_id * element_size;
	main_elements.insert(insert_it, pend_begin, pend_begin + element_size);
	pend_elements.erase(pend_begin, pend_begin + element_size);
	insert_pending(main_elements, pend_elements, element_size);
}

template <typename T>
void merge_insert(T &elements, size_t element_size)
{
	if (is_sorted(elements))
		return;
	size_t element_count = elements.size() / element_size;
	std::cout << "------------" << std::endl;
	std::cout << "Comparisons: " << comparisons;
	std::cout << ", Size: " << element_size;
	std::cout << ", Count: " << element_count << std::endl;
	print_elements(elements, element_size);

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

	if (is_sorted(elements))
		return;

	std::cout << "------------" << std::endl;;
	std::cout << "Comparisons: " << comparisons;
	std::cout << ", Size: " << element_size;
	std::cout << ", Count: " << element_count << std::endl;
	print_elements(elements, element_size);

	// split elements to main and pend
	T main_elements, pend_elements, leftovers;
	for (size_t i = 0; i < element_count; ++i)
	{
		// get element iterator
		auto element_it = elements.begin() + i * element_size;
		print_element(element_it, element_size);

		// first element and all odds are main
		if (i == 0 || i % 2 == 1)
		{
			main_elements.insert(main_elements.end(), element_it, element_it + element_size);
			std::cout << "Moved to main" << std::endl;
			continue;
		}

		// rest are pend
		pend_elements.insert(pend_elements.begin(), element_it, element_it + element_size);
		std::cout << "Moved to pend" << std::endl;
	}

	// save leftovers
	for (size_t i = element_count * element_size; i < elements.size(); ++i)
		leftovers.push_back(elements[i]);

	insert_pending(main_elements, pend_elements, element_size);

	// replace elements with the sorted main_elements
	elements = main_elements;
	elements.insert(elements.end(), leftovers.begin(), leftovers.end());
}

#endif
