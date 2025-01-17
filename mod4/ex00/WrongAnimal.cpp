#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("") { std::cout << "WrongAnimal default constructor" << std::endl; }

WrongAnimal::WrongAnimal(const std::string& type) : type(type) { std::cout << "WrongAnimal constructor with type" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) { std::cout << "WrongAnimal copy constructor" << std::endl; }

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignment" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor" << std::endl; }

void WrongAnimal::makeSound() const
{
    if (type == "WrongCat")
        std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }