#include "AMateria.hpp"

// default constructor
AMateria::AMateria() : type("") {}

// constructor with type
AMateria::AMateria(std::string const & type) : type(type) {}

// copy constructor
AMateria::AMateria(const AMateria& other) : type(other.getType()) {}

// copy assignment
AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

// getters
std::string const & AMateria::getType() const { return type; }

// destructor
AMateria::~AMateria() {}