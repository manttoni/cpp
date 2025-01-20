#include "Character.hpp"

Character::Character() : ICharacter() {}

Character::Character(const Character& other) : ICharacter(other) {}

Character& Character::operator=(const Character& other)
{
    ICharacter::operator=(other);
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
    {
        delete slots[i];
        slots[i] = nullptr;
    }
}

Character::Character(const std::string& name) : ICharacter(name) {}

std::string const & Character::getName() const { return name; }

void Character::equip(AMateria* m)
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

void Character::use(int idx, ICharacter& target)
{
    if (slots[idx] == nullptr)
        return;
    slots[idx]->use(target);
}