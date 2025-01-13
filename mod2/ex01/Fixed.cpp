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
	this->value = other.getRawBits();
}

// With initial integer value
Fixed::Fixed(const int value)
{
	int tmp = value;
	tmp <<= 8;
	tmp >>= 8;
	if (tmp != value)
		std::cout << "value changed" << std::endl;
	std::cout << "Integer constructor called" << std::endl;
	this->value = value << 8;
}

// With initial floating point value
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
		this->value = other.getRawBits();
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
	return value / pow(2, fract_bits);
}

// Returns an int
int Fixed::toInt(void) const
{
	return value >> fract_bits;
}