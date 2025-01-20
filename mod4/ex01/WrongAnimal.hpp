#ifndef WRONGAnimal_HPP
#define WRONGAnimal_HPP

#include <string>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const std::string& type);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        ~WrongAnimal();
        
        void makeSound() const;
        std::string getType() const;
};

#endif