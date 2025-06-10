#include "PmergeMe.hpp"
#include <vector>
#include <cassert>
#include <iostream>
#include <deque>

// Rightmost number is the value of the element
int get_highest(auto it, size_t element_size)
{
	return it[element_size - 1];
}

std::vector<std::string> get_labels_vector(const size_t element_count)
{
	std::vector<std::string> labels;
	for (size_t i = 0; i < element_count; ++i)
	{
		if (i % 2 == 0)
			labels.push_back("b" + std::to_string(i / 2));
		else
			labels.push_back("a" + std::to_string(i / 2));
	}
	return labels;
}

// sequence 1,3,5,11,21,43...
std::vector<size_t> jacobstahl_vector(const int n)
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

// get order in which pend elements are inserted to main chain
std::vector<size_t> get_jacobstahl_order_vector(const size_t len)
{
	std::vector<size_t> order;
	std::vector<size_t> jacob_numbers = jacobstahl_vector(len);

	for (size_t i = 1; i < jacob_numbers.size(); ++i)
	{
		size_t prev = jacob_numbers[i - 1];
		size_t curr = jacob_numbers[i];
		size_t diff = curr - prev;
		for (size_t j = diff; j > 0; --j)
			order.push_back(prev + j);
	}
	return order;
}

void merge_insert_vector(std::vector<int> &elements, const size_t element_size)
{
	const size_t element_count = elements.size() / element_size;
	if (is_sorted(elements, element_size))
		return;
	swap_pairs(elements, element_size);
	merge_insert_vector(elements, element_size * 2);
	if (is_sorted(elements, element_size))
		return;

	std::vector<std::string> labels = get_labels_vector(element_count);
	std::vector<int> main_chain, pend, leftovers;
	for (size_t i = 0; i < element_count; ++i)
	{
		auto element = elements.begin() + i * element_size;
		if (labels[i].front() == 'a' || i == 0)
			main_chain.insert(main_chain.end(), element, element + element_size);
		else
			pend.insert(pend.end(), element, element + element_size);
	}

	for (size_t i = element_count - 1; i + 1 >= 1; --i)
		if (labels[i].front() == 'b' && labels[i][1] != '0')
			labels.erase(labels.begin() + i);

	for (size_t i = element_count * element_size; i < elements.size(); ++i)
		leftovers.push_back(elements[i]);

	assert(elements.size() == main_chain.size() + pend.size() + leftovers.size());
	assert(main_chain.size() / element_size == labels.size());

	std::vector<size_t> jacobstahl_order = get_jacobstahl_order_vector(element_count);
	size_t pend_size = pend.size() / element_size;
	std::vector<bool> inserted(pend_size, false);
	for (size_t i = 0; i < pend_size; ++i)
	{
		assert(main_chain.size() / element_size == labels.size());
		size_t jix = jacobstahl_order[i];
		size_t pend_i = jix - 2;

		size_t search_max = main_chain.size() / element_size;
		auto bound_label = std::find(labels.begin(), labels.end(), "a" + std::to_string(jix));
		if (bound_label != labels.end())
			search_max = std::distance(labels.begin(), bound_label) - 1;

		assert(search_max <= main_chain.size() / element_size);
		if (pend_i >= pend_size || inserted[pend_i] == true)
		{
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
		size_t insert_ix = search_lower(main_chain, search_max, pend_element, element_size);
		main_chain.insert(main_chain.begin() + insert_ix * element_size, pend_element, pend_element + element_size);
		assert(is_sorted(main_chain, element_size));
		labels.insert(labels.begin() + insert_ix, "b" + std::to_string(pend_i + 2));
		inserted[pend_i] = true;
	}
	elements = main_chain;
	elements.insert(elements.end(), leftovers.begin(), leftovers.end());
	assert(element_count == elements.size() / element_size);
}

////// /* SAME WITH DEQUE */ //////

std::deque<std::string> get_labels_deque(const size_t element_count)
{
	std::deque<std::string> labels;
	for (size_t i = 0; i < element_count; ++i)
	{
		if (i % 2 == 0)
			labels.push_back("b" + std::to_string(i / 2));
		else
			labels.push_back("a" + std::to_string(i / 2));
	}
	return labels;
}

// sequence 1,3,5,11,21,43...
std::deque<size_t> jacobstahl_deque(const int n)
{
	std::deque<size_t> jacob = {1, 3};
	while (true)
	{
		int next = jacob.back() + jacob[jacob.size() - 2] * 2;
		if (next > n)
			break;
		jacob.push_back(next);
	}
	return jacob;
}

// get order in which pend elements are inserted to main chain
std::deque<size_t> get_jacobstahl_order_deque(const size_t len)
{
	std::deque<size_t> order;
	std::deque<size_t> jacob_numbers = jacobstahl_deque(len);

	for (size_t i = 1; i < jacob_numbers.size(); ++i)
	{
		size_t prev = jacob_numbers[i - 1];
		size_t curr = jacob_numbers[i];
		size_t diff = curr - prev;
		for (size_t j = diff; j > 0; --j)
			order.push_back(prev + j);
	}
	return order;
}

void merge_insert_deque(std::deque<int> &elements, const size_t element_size)
{
	const size_t element_count = elements.size() / element_size;
	if (is_sorted(elements, element_size))
		return;
	swap_pairs(elements, element_size);
	merge_insert_deque(elements, element_size * 2);
	if (is_sorted(elements, element_size))
		return;

	std::deque<std::string> labels = get_labels_deque(element_count);
	std::deque<int> main_chain, pend, leftovers;
	for (size_t i = 0; i < element_count; ++i)
	{
		auto element = elements.begin() + i * element_size;
		if (labels[i].front() == 'a' || i == 0)
			main_chain.insert(main_chain.end(), element, element + element_size);
		else
			pend.insert(pend.end(), element, element + element_size);
	}

	for (size_t i = element_count - 1; i + 1 >= 1; --i)
		if (labels[i].front() == 'b' && labels[i][1] != '0')
			labels.erase(labels.begin() + i);

	for (size_t i = element_count * element_size; i < elements.size(); ++i)
		leftovers.push_back(elements[i]);

	assert(elements.size() == main_chain.size() + pend.size() + leftovers.size());

	std::deque<size_t> jacobstahl_order = get_jacobstahl_order_deque(element_count);
	size_t pend_size = pend.size() / element_size;
	std::deque<bool> inserted(pend_size, false);
	for (size_t i = 0; i < pend_size; ++i)
	{
		size_t jix = jacobstahl_order[i];
		size_t pend_i = jix - 2;

		size_t search_max = main_chain.size() / element_size;
		auto bound_label = std::find(labels.begin(), labels.end(), "a" + std::to_string(jix));
		if (bound_label != labels.end())
			search_max = std::distance(labels.begin(), bound_label) - 1;

		if (pend_i >= pend_size || inserted[pend_i] == true)
		{
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
		size_t insert_ix = search_lower(main_chain, search_max, pend_element, element_size);
		main_chain.insert(main_chain.begin() + insert_ix * element_size, pend_element, pend_element + element_size);
		assert(is_sorted(main_chain, element_size));
		labels.insert(labels.begin() + insert_ix, "b" + std::to_string(pend_i + 3));
		inserted[pend_i] = true;
	}
	elements = main_chain;
	elements.insert(elements.end(), leftovers.begin(), leftovers.end());
	assert(element_count == elements.size() / element_size);
}
