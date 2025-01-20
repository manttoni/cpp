#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
    protected:
        AMateria *slots[4];
    public:
        IMateriaSource();
        IMateriaSource(const IMateriaSource& other);
        IMateriaSource& operator=(const IMateriaSource& other);
        virtual ~IMateriaSource() {}
        
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif