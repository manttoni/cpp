#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") { std::cout << "Cat default constructor" << std::endl; }

Cat::Cat(const Cat& other) : type(other.type) { std::cout << "Cat copy constructor" << std::endl; }

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment" << std::endl;
    (void) other;
    return *this;
}

Cat::~Cat() { std::cout << "Cat destructor" << std::endl; }