#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>

extern size_t numbers_total;
extern int comparisons;
#define DEBUG false

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
void print_elements(const std::vector<int> &elements, size_t element_size)
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
void print_numbers(const std::vector<int> &numbers)
{
	print_element(numbers.begin(), numbers.size());
}

int get_highest(auto it, size_t element_size)
{
	return it[element_size - 1];
}

// find the lower_bound index for element in main_elements
size_t search_lower(const std::vector<int> &main_chain, size_t end, auto element, const size_t element_size)
{
	auto main_begin = main_chain.begin();
	int ele_value = get_highest(element, element_size);
	size_t begin = 0;
	if (ele_value <= main_begin[element_size - 1])
	{
		if (DEBUG == true) std::cout << ele_value << " is smallest" << std::endl;
		return 0;
	}
	if (ele_value >= get_highest(main_begin, main_chain.size()))
	{
		if (DEBUG == true) std::cout << ele_value << " is largest" << std::endl;
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
			if (DEBUG == true) std::cout << ele_value << " <= " << mid_value << std::endl;
			end = middle;
		}
		else
		{
			if (DEBUG == true) std::cout << ele_value << " > " << mid_value << std::endl;
			begin = middle + 1;
		}
	}
	return begin;
}

// return true if every element is "sorted", counting the highest/rightmost value only
bool is_sorted(std::vector<int> elements, size_t element_size)
{
	size_t element_count = elements.size() / element_size;
	for (size_t i = 0; i < element_count - 1; i += 1)
	{
		auto curr = elements.begin() + i * element_size;
		auto next = elements.begin() + (i + 1) * element_size;
		int currhigh = get_highest(curr, element_size);
		int nexthigh = get_highest(next, element_size);
		if (currhigh > nexthigh)
		{
			return false;
		}
	}
	return true;
}

std::vector<size_t> jacobstahl(const int n)
{
	std::vector<size_t> jacob = {1, 3};
	while (true)
	{
		int next = jacob.back() + jacob[jacob.size() - 2] * 2;
		if (next > n)
			break;
		jacob.push_back(next);
	}
	return jacob;
}

void print_debug(std::vector<int> &elements, size_t element_size)
{
	if (DEBUG == true)
	{
		std::cout << "--------------" << std::endl;
		print_elements(elements, element_size);
	}
}

void swap_pairs(std::vector<int> &elements, size_t element_size)
{
	// check if can form 2 elements
	if (element_size * 2 > elements.size())
		return;

	size_t element_count = elements.size() / element_size;
	print_debug(elements, element_size);

	// swap elements to sort
	for (size_t i = 0; i + 1 < element_count; i += 2)
	{
		comparisons++;
		auto left_begin = elements.begin() + i * element_size;
		auto right_begin = left_begin + element_size;

		if (get_highest(left_begin, element_size) <= get_highest(right_begin, element_size))
		{
			if (DEBUG == true) std::cout << "No swap" << std::endl;
			continue;
		}

		if (DEBUG == true)
		{
			print_element(left_begin, element_size);
			std::cout << " <=> ";
			print_element(right_begin, element_size);
			std::cout << std::endl;
		}

		std::swap_ranges(left_begin, left_begin + element_size, right_begin);
	}
}

std::vector<std::string> get_labels(const size_t element_count)
{
	std::vector<std::string> labels;
	for (size_t i = 0; i < element_count; ++i)
	{
		if (i % 2 == 0)
			labels.push_back("b" + std::to_string(i / 2));
		else
			labels.push_back("a" + std::to_string(i / 2));
	}

	if (DEBUG == true)
	{
		std::cout << "Labels: ";
		for (size_t j = 0; j < labels.size(); ++j)
			std::cout << labels[j] << " ";
		std::cout << std::endl;
	}

	return labels;
}

std::vector<size_t> get_jacobstahl_order(const size_t len)
{
	std::vector<size_t> order;
	std::vector<size_t> jacob_numbers = jacobstahl(len);

	for (size_t i = 1; i < jacob_numbers.size(); ++i)
	{
		size_t prev = jacob_numbers[i - 1];
		size_t curr = jacob_numbers[i];
		size_t diff = curr - prev;
		for (size_t j = diff; j > 0; --j)
		{
			order.push_back(prev + j);
		}
	}
	return order;
}

void merge_insert(std::vector<int> &elements, const size_t element_size)
{
	const size_t element_count = elements.size() / element_size;
	if (is_sorted(elements, element_size))
		return;

	swap_pairs(elements, element_size);
	if (DEBUG == true) std::cout << "Comparisons: " << comparisons << std::endl;
	merge_insert(elements, element_size * 2);
	print_debug(elements, element_size);

	if (is_sorted(elements, element_size))
		return;

	std::vector<std::string> labels = get_labels(element_count);

	std::vector<int> main_chain, pend, leftovers;
	for (size_t i = 0; i < element_count; ++i)
	{
		auto element = elements.begin() + i * element_size;
		if (labels[i].front() == 'a' || i == 0)
		{
			main_chain.insert(main_chain.end(), element, element + element_size);
		}
		else
		{
			pend.insert(pend.end(), element, element + element_size);
		}
	}

	// erase pend labels
	for (size_t i = element_count - 1; i + 1 >= 1; --i)
	{
		if (labels[i].front() == 'b' && labels[i].back() != '0')
			labels.erase(labels.begin() + i);
	}

	for (size_t i = element_count * element_size; i < elements.size(); ++i)
		leftovers.push_back(elements[i]);

	assert(elements.size() == main_chain.size() + pend.size() + leftovers.size());

	std::vector<size_t> jacobstahl_order = get_jacobstahl_order(element_count);
	size_t pend_size = pend.size() / element_size;
	std::vector<bool> inserted(pend_size, false);
	for (size_t i = 0; i < pend_size; ++i)
	{
		size_t jix = jacobstahl_order[i];
		size_t pend_i = jix - 2;

		// define search area for binary search
		size_t search_max = main_chain.size() / element_size;
		auto bound_label = std::find(labels.begin(), labels.end(), "a" + std::to_string(jix));
		if (bound_label != labels.end())
			search_max = std::distance(labels.begin(), bound_label) - 1;

		if (pend_i >= pend_size || inserted[pend_i] == true)
		{
			if (DEBUG == true)
				std::cout << "Cant use jacob, using next free index in reverse order" << std::endl;

			for (size_t j = pend_size - 1; j + 1 >= 1; --j)
			{
				if (inserted[j] == false)
				{
					pend_i = j;
					break;
				}
			}
		}

		auto pend_element = pend.begin() + pend_i * element_size;

		if (DEBUG == true)
		{
			std::cout << "----------------" << std::endl;
			std::cout << "Used indices: ";
			for (size_t j = 0; j < pend_size; ++j)
				std::cout << inserted[j] << " ";
			std::cout << std::endl;
			std::cout << "Main chain: ";
			print_elements(main_chain, element_size);
			std::cout << "Labels: ";
			for (size_t j = 0; j < labels.size(); ++j)
				std::cout << labels[j] << " ";
			std::cout << std::endl;
			std::cout << "Pend: ";
			for (size_t j = 0; j < pend_size; ++j)
			{
				if (inserted[j] == true)
					continue;
				print_element(pend.begin() + j * element_size, element_size);
				std::cout << " ";
			}
			std::cout << std::endl;
			std::cout << "Leftovers: ";
			print_elements(leftovers, leftovers.size());
			std::cout << "Jacobstahl insertion order value: " << jix << std::endl;
			std::cout << "Element count: " << element_count << ", element size: " << element_size << std::endl;
			std::cout << "Search max: " << search_max << std::endl;
			std::cout << "Selected pend index: " << pend_i << ", element: ";
			print_element(pend_element, element_size);
			std::cout << std::endl;
		}

		size_t insert_ix = search_lower(main_chain, search_max, pend_element, element_size);
		if (DEBUG == true)
		{
			std::cout << "Comparisons: " << comparisons << std::endl;
			std::cout << "Insert_ix: " << insert_ix << ", " << get_highest(pend_element, element_size) << " to " << get_highest(main_chain.begin() + insert_ix * element_size, element_size) << std::endl;
		}

		main_chain.insert(main_chain.begin() + insert_ix * element_size, pend_element, pend_element + element_size);
		assert(is_sorted(main_chain, element_size));
		labels.insert(labels.begin() + insert_ix, "b" + std::to_string(pend_i + 3));
		inserted[pend_i] = true;
	}


	// replace elements with the sorted main_elements
	elements = main_chain;
	elements.insert(elements.end(), leftovers.begin(), leftovers.end());
	assert(element_count == elements.size() / element_size);
}

#endif
