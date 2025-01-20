#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other) {}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    IMateriaSource::operator=(other);
    return *this;
}

MateriaSource::~MateriaSource() { for (int i = 0; i < 4; ++i) delete slots[i]; }

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (slots[i] == nullptr)
        {
            slots[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
        if (slots[i] != nullptr && slots[i]->getType() == type)
            return slots[i]->clone();
    return 0;
}