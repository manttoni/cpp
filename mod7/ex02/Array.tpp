#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : data(nullptr), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), len(n) {}

template <typename T>
Array<T>::Array(const Array &other) : data(new T[other.len]()), len(other.len) 
{
	for (size_t i= 0; i < len; ++i)
		data[i] = other.data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;
	delete[] data;
	len = other.len;
	data = new T[len];
	for (size_t i = 0; i < len; ++i)
		data[i] = other.data[i];
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= len)
		throw std::out_of_range("Index out of bounds");
	return data[n];
}

template <typename T>
size_t Array<T>::size() const
{
	return len;
}