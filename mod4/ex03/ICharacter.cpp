#include "ICharacter.hpp"

ICharacter::ICharacter() : name("")
{
    for (int i = 0; i < 4; ++i)
        slots[i] = nullptr;
}

ICharacter::ICharacter(const ICharacter& other) : name(other.name)
{
    for(int i = 0; i < 4; ++i)
    {
        delete slots[i];
        slots[i] = other.slots[i];
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
        slots[i] = other.slots[i];
    }
    return *this;
}

ICharacter::ICharacter(const std::string& name) : name(name)
{
    for (int i = 0; i < 4; ++i)
        slots[i] = nullptr;
}

ICharacter::~ICharacter() {};