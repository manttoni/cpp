#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data
{
	int value1;
	int value2;
};

class Serializer
{
	public:
		Serializer() = delete;
		Serializer(const Serializer& other) = delete;
		Serializer& operator=(const Serializer& other) = delete;
		~Serializer() = delete;

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif