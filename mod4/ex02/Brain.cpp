#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor" << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = "";
    no_ideas = 0;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor" << std::endl;
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
    no_ideas = other.no_ideas;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment" << std::endl;
    if (this == &other)
        return *this;
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
    no_ideas = other.no_ideas;
    return *this;
}

Brain::~Brain() {std::cout << "Brain destructor" << std::endl; }

void Brain::addIdea(const std::string& idea)
{
    ideas[no_ideas] = idea;
    no_ideas++;
}

void Brain::printIdeas() const
{
    for (unsigned int i = 0; i < no_ideas; ++i)
        std::cout << ideas[i] << std::endl;
}