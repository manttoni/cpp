#include "Fixed.hpp"
#include <iostream>

// Shared between all Fixed objects. Cannot change = is constant
const int Fixed::fract_bits = 8;

// Constructors
// Default
Fixed::Fixed() : value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy
Fixed::Fixed(const Fixed& other) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;;
}

// With initial integer value
// value has to be maximum 24 bits long, otherwise it will be truncated
Fixed::Fixed(const int value)
{
	std::cout << "Integer constructor called" << std::endl;
	this->value = value << fract_bits;
}

// With initial floating point value
// int value has to be maximum 24 bits long, otherwise it will be truncated
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = value * (1 << fract_bits) + 0.5;
}

// Operators
// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.value;
	return *this;
}

// Insertion operator (<<)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
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

// Converters
// Returns a float
float Fixed::toFloat(void) const
{
	return value / (float)(1 << fract_bits);
}

// Returns an int
int Fixed::toInt(void) const
{
	return value >> fract_bits;
}