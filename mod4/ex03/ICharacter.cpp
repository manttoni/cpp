#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter() : name("") { for (int i = 0; i < 4; ++i) slots[i] = nullptr; }

ICharacter::ICharacter(const ICharacter& other) : name(other.name)
{
    for(int i = 0; i < 4; ++i)
    {
        if (other.slots[i] != nullptr)
            slots[i] = other.slots[i]->clone();
        else
            slots[i] = nullptr;
    }
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
    if (this == &other)
        return *this;
    this->name = other.name;
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

ICharacter::ICharacter(const std::string& name) : name(name)
{
    for (int i = 0; i < 4; ++i)
        slots[i] = nullptr;
}

ICharacter::~ICharacter() {};