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

int get_highest(auto it, size_t element_size)
{
	return it[element_size - 1];
}

// find the lower_bound index for element in main_elements
size_t search_lower(auto main_begin, size_t search_max, auto element, size_t element_size)
{
	int ele_value = get_highest(element, element_size);
	size_t begin = 0;
	size_t end = search_max;
	while (begin < end)
	{
		comparisons++;
		size_t middle = begin + (end - begin) / 2;
		int mid_value = get_highest(main_begin + middle * element_size, element_size);
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

// return true if every element is "sorted", counting the highest/rightmost value only
bool is_sorted(std::vector<int> elements, size_t element_size)
{
	size_t element_count = elements.size() / element_size;
	print_elements(elements, element_size);
	for (size_t i = 0; i < element_count - 1; i += 1)
	{
		auto curr = elements.begin() + i * element_size;
		auto next = elements.begin() + (i + 1) * element_size;
		int currhigh = get_highest(curr, element_size);
		int nexthigh = get_highest(next, element_size);
		std::cout << "Comparison: " << currhigh << " vs " << nexthigh << std::endl;
		if (currhigh > nexthigh)
		{
			std::cout << " is not sorted at " << i << std::endl;
			return false;
		}
	}
	std::cout << " is sorted, count: " << element_count << std::endl;
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
void print_debug(T &elements, size_t element_size)
{
	std::cout << "--------------" << std::endl;
	print_elements(elements, element_size);
}

template <typename T>
void swap_pairs(T &elements, size_t element_size)
{
	// check if can form 2 elements
	if (element_size * 2 > elements.size())
	{
		std::cout << "Can't swap" << std::endl;
		return;
	}

	std::cout << "Swapping" << std::endl;

	size_t element_count = elements.size() / element_size;

	// swap elements to sort
	for (size_t i = 0; i + 1 < element_count; i += 2)
	{
		print_debug(elements, element_size);
		comparisons++;
		auto left_begin = elements.begin() + i * element_size;
		auto right_begin = left_begin + element_size;

		if (get_highest(left_begin, element_size) <= get_highest(right_begin, element_size))
		{
			std::cout << "No swap needed at ";
			print_element(left_begin, element_size);
			std::cout << std::endl;
			continue;
		}

		print_element(left_begin, element_size);
		std::cout << " <=> ";
		print_element(right_begin, element_size);
		std::cout << std::endl;

		std::swap_ranges(left_begin, left_begin + element_size, right_begin);
	}
}

std::vector<std::string> get_labels(const size_t element_count)
{
	std::vector<std::string> labels;
	for (size_t i = 0; i < element_count; ++i)
	{
		if (i % 2 == 0)
			labels.push_back("b" + std::to_string(i));
		else
			labels.push_back("a" + std::to_string(i));
	}
	return labels;
}

std::vector<size_t> get_jacobstahl_order(const size_t element_count)
{
	(void) element_count;
	std::vector<size_t> order = {3,2,5,4,11,10,9,8,7,6};
	return order;
}

void merge_insert(std::vector<int> &elements, size_t element_size)
{
	if (is_sorted(elements, element_size))
		return;
	size_t element_count = elements.size() / element_size;


	swap_pairs(elements, element_size);

	merge_insert(elements, element_size * 2);

	if (is_sorted(elements, element_size))
		return;

	std::vector<std::string> labels = get_labels(element_count);

	std::vector<int> main_chain, pend, leftovers;
	for (size_t i = 0; i < element_count; ++i)
	{
		auto element = elements.begin() + i * element_size;
		if (labels[i].front() == 'a' || i == 0)
			main_chain.insert(main_chain.end(), element, element + element_size);
		else
			pend.insert(pend.end(), element, element + element_size);
	}

	for (size_t i = element_count * element_size; i < elements.size(); ++i)
		leftovers.push_back(elements[i]);

	std::vector<size_t> jacobstahl_order = get_jacobstahl_order(element_count);
	size_t pend_size = pend.size() / element_size;
	std::vector<bool> inserted(pend_size, false);
	for (size_t i = 0; i < pend_size; ++i)
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Main chain: ";
		print_elements(main_chain, element_size);
		std::cout << "Pend: ";
		print_elements(pend, element_size);
		std::cout << "Leftovers: ";
		print_elements(leftovers, leftovers.size());

		size_t jix = jacobstahl_order[i];
		std::cout << "Jacob number: " << jix << std::endl;
		size_t pend_i = jix - 2;
		std::cout << "Pend index: " << pend_i << std::endl;
		if (pend_i >= pend_size)
		{
			std::cout << "Cant use jacob" << std::endl;
			for (size_t asd = 0; asd < pend_size; ++asd)
				std::cout << inserted[asd] << " ";
			std::cout << std::endl;
			for (size_t j = 0; j < pend_size; ++j)
			{
				if (inserted[j] == false)
				{
					pend_i = j;
					break;
				}
			}
		}

		if (inserted[pend_i] == true)
			continue;

		auto pend_element = pend.begin() + pend_i * element_size;
		std::cout << "Selected pend index: " << pend_i << ", element: ";
		print_element(pend_element, element_size);
		std::cout << std::endl;

		size_t search_max = main_chain.size() / element_size;
		size_t insert_ix = search_lower(main_chain.begin(), search_max, pend_element, element_size);
		main_chain.insert(main_chain.begin() + insert_ix * element_size, pend_element, pend_element + element_size);
		labels.insert(labels.begin() + insert_ix, "b" + std::to_string(pend_i + 3));
		std::cout << "Setting true to " << pend_i << std::endl;
		inserted[pend_i] = true;
	}

	// replace elements with the sorted main_elements
	elements = main_chain;
	elements.insert(elements.end(), leftovers.begin(), leftovers.end());
}

#endif
