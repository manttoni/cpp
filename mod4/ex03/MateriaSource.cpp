#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource() : IMateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other) {}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this == &other)
        return *this;
    for (int i = 0; i < 4; ++i)
    {
        delete slots[i];
        slots[i] = other.slots[i];
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        delete slots[i];
        slots[i] = nullptr;
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (slots[i] == nullptr)
        {
            if (m->getType() == "ice")
                slots[i] = new Ice();
            else if (m->getType() == "cure")
                slots[i] = new Cure();
            break;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (type != "ice" && type != "cure")
        return 0;
    for (int i = 0; i < 4; ++i)
    {
        if (slots[i]->getType() == type)
            return slots[i]->clone();
    }
    return nullptr;
}