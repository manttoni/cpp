#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	std::cout << std::endl << "-- Initializing Data struct --" << std::endl;
	Data d = {1,2};
	std::cout << "Address of d: " << &d << std::endl;
	std::cout << "Values inside d:" << std::endl;
	std::cout << "value1: " << d.value1 << std::endl;
	std::cout << "value2: " << d.value2 << std::endl;

	std::cout << std::endl << "-- Serializing... --" << std::endl;
	uintptr_t uintptr_d = Serializer::serialize(&d);
	std::cout << "Data as uintptr_t: " << uintptr_d << std::endl;
	Data* ptr_d = Serializer::deserialize(uintptr_d);
	std::cout << "uintptr_d as Data*: " << ptr_d << std::endl;

	std::cout << std::endl << "-- Serializing and deserializing done --" << std::endl;
	std::cout << "Address of d: " << &d << std::endl;
	std::cout << "d_ptr: " << ptr_d << std::endl;
	std::cout << "Values inside d:" << std::endl;
	std::cout << "value1: " << ptr_d->value1 << std::endl;
	std::cout << "value2: " << ptr_d->value2 << std::endl;
	return 0;
}