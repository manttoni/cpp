#include "AMateria.hpp"

AMateria::AMateria() : type("") {}

AMateria::AMateria(const AMateria& other) : type(other.getType()) {}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return type;
}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}