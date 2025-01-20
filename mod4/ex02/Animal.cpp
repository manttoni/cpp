#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("") { std::cout << "Animal default constructor" << std::endl; }

Animal::Animal(const std::string& type) : type(type) { std::cout << "Animal constructor with type" << std::endl; }

Animal::Animal(const Animal& other) : type(other.type) { std::cout << "Animal copy constructor" << std::endl; }

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

Animal::~Animal() { std::cout << "Animal destructor" << std::endl; }

void Animal::makeSound() const
{
    if (type == "Cat")
        std::cout << "Meow" << std::endl;
    else if (type == "Dog")
        std::cout << "Bark" << std::endl;
}

std::string Animal::getType() const { return type; }

void Animal::setType(const std::string& type)
{
    this->type = type;
}