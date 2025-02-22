#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") 
{
    std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Dog()
{
    std::cout << "Dog copy constructor" << std::endl;
    (void) other;   
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment" << std::endl;
    (void) other;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "bark" << std::endl;
}