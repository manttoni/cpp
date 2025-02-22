#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog") 
{
    std::cout << "Dog default constructor" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal("Dog")
{
    std::cout << "Dog copy constructor" << std::endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment" << std::endl;
    if (this == &other)
        return *this;
    delete brain;
    brain = new Brain(*other.brain);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}

Brain& Dog::getBrain() const
{
    return *brain;
}

void Dog::addIdea(const std::string& idea)
{
    brain->addIdea(idea);
}