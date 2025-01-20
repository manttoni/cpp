#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
    for (int i = 0; i < 4; ++i)
        slots[i] = nullptr;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
    for (int i = 0; i < 4; ++i)
    {
        delete slots[i];
        slots[i] = other.slots[i];
    }
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
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