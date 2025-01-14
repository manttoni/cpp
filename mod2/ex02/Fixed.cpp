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
	std::cout << "Integer constructor called with value " << value << std::endl;
	this->value = value << fract_bits;
}

// With initial floating point value
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called with value " << value << std::endl;
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

bool Fixed::operator>(const Fixed& other)
{
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other)
{
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other)
{
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other)
{
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other)
{
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other)
{
	return this->value != other.value;
}

// Arithmetics
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed tmp;
	tmp.setRawBits(value + other.value);
	return tmp;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed tmp;
	tmp.setRawBits(value - other.value);
	return tmp;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	long tmp_value = value;
	tmp_value *= other.value;
	tmp_value >>= fract_bits;
	Fixed tmp = Fixed((int)tmp_value);
	return tmp;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	int tmp_value = (value / other.value);
	tmp_value <<= fract_bits;
	Fixed tmp = Fixed(tmp_value);
	return tmp;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	value += 1;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	value -= 1;
	return tmp;
}

Fixed& Fixed::operator++()
{
	value += 1;
	return *this;
}

Fixed& Fixed::operator--()
{
	value -= 1;
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
	std::cout << "Destructor called for Fixed with value " << toFloat() << std::endl;
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

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.value < b.value)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.value > b.value)
		return a;
	return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.value < b.value)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.value > b.value)
		return a;
	return b;
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