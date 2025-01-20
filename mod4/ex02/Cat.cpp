#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat") 
{
    std::cout << "Cat default constructor" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat& other)
{
    std::cout << "Cat copy constructor" << std::endl;
    setType("Cat");
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment" << std::endl;
    if (this == &other)
        return *this;
    delete brain;
    brain = new Brain(*other.brain);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
    delete brain;
}

Brain& Cat::getBrain() const
{
    return *brain;
}

void Cat::addIdea(const std::string& idea)
{
    brain->addIdea(idea);
}