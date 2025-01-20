#include <iostream>
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : Cure() { (void) other; }

Cure& Cure::operator=(const Cure& other)
{
    (void) other;
    return *this; // Cure is always Cure
}

Cure::~Cure() {}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure* Cure::clone() const
{
    return new Cure(*this);
}