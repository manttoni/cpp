#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
unsigned int easyfind(T &con, int i)
{
	typename T::iterator it = std::find(con.begin(), con.end(), i);

	if (it == con.end())
		throw std::runtime_error("not found");

	return std::distance(con.begin(), it);
}

#endif