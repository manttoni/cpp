#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	// define the mutantstack from subject example
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.pop();
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	// define the same but with std::list
	std::list<int> mylist;
	mylist.push_back(5);
	mylist.push_back(17);
	mylist.pop_back();
	mylist.push_back(3);
	mylist.push_back(5);
	mylist.push_back(737);
	mylist.push_back(0);

	std::list<int>::iterator listit = mylist.begin();
	std::list<int>::iterator listite = mylist.end();

	++listit;
	--listit;

	if (std::distance(listit, listite) != std::distance(it, ite))
	{
		std::cout << "The containers have different max distance" << std::endl;
		return 2;
	}

	while (listit != listite)
	{
		if (*listit != *it)
		{
			std::cout << "The numbers don't match" << std::endl;
			return 1;
		}
		listit++;
		it++;
	}
	std::cout << "The containers are identical in elements and their amount" << std::endl;
	return 0;
}

