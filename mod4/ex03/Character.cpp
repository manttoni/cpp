#include "Character.hpp"

Character::Character() : ICharacter()
{
    for (int i = 0; i < 4; ++i)
        slots[i] = nullptr;
}

Character::Character(const Character &other) : ICharacter()
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.slots[i] != nullptr)
            slots[i] = other.slots[i]->clone();
        else
            slots[i] = nullptr;
    }
}

Character &Character::operator=(const Character &other)
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

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete slots[i];
}

Character::Character(const std::string &name) : ICharacter(), name(name)
{
    for (int i = 0; i < 4; ++i)
        slots[i] = nullptr;
}

std::string const &Character::getName() const { return name; }

void Character::equip(AMateria *m)
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

void Character::unequip(int idx) { slots[idx] = nullptr; }

void Character::use(int idx, ICharacter &target)
{
    if (slots[idx] != nullptr)
        slots[idx]->use(target);
}