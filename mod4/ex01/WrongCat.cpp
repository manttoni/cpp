#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << "WrongCat default constructor" << std::endl; }

WrongCat::WrongCat(const WrongCat& other) : WrongCat() { (void) other; std::cout << "WrongCat copy constructor" << std::endl; }

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment" << std::endl;
    (void) other;
    return *this;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor" << std::endl; }