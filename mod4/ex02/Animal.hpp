#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const std::string& type);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        
        virtual void addIdea(const std::string& idea) = 0;
        virtual Brain& getBrain() const = 0;
        virtual void makeSound() const = 0;

        void setType(const std::string& type);
        std::string getType() const;
};

#endif