#include "Fixed.hpp"
#include <iostream>

// Shared between all Fixed objects
const int Fixed::fract_bits = 8;

// Default
Fixed::Fixed() : value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy
Fixed::Fixed(const Fixed& other) 
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

// Destructor
Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

// Setter
void Fixed::setRawBits(int newValue)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = newValue;
}