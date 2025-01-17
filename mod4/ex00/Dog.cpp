#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") { std::cout << "Dog default constructor" << std::endl; }

Dog::Dog(const Dog& other) : type(other.type) { std::cout << "Dog copy constructor" << std::endl; }

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment" << std::endl;
    (void) other;
    return *this;
}

Dog::~Dog() { std::cout << "Dog destructor" << std::endl; }