#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() { for (int i = 0; i < 4; ++i) slots[i] = nullptr; }

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.slots[i] != nullptr)
            slots[i] = other.slots[i]->clone();
        else
            slots[i] = nullptr;
    }
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
{
    if (this == &other)
        return *this;
    for (int i = 0; i < 4; ++i)
    {
        delete slots[i];
        if (other.slots[i] != nullptr)
            slots[i] = other.slots[i]->clone();
        else
            slots[i] = nullptr;
    }
    return *this;
}