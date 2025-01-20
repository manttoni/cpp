#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        Brain& getBrain() const;
        void addIdea(const std::string& idea);
};

#endif