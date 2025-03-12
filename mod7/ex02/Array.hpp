#ifndef ARRAY_H
#define ARRAY_H

#include <cstdlib>

template <typename T>
class Array
{
	private:
		T *data;
		size_t len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();
		
		T& operator[](unsigned int n);
		size_t size() const;
};

#include "Array.tpp"

#endif