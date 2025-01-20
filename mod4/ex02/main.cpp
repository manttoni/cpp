#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    // uncomment next line so it will not compile because Animal is an abstract class
    // Animal animal = Animal();

    std::cout << "Read main.cpp" << std::endl;

    return 0;
}