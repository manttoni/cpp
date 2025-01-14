#include "Fixed.hpp"
#include <iostream>

// Shared between all Fixed objects. Cannot change = is constant
const int Fixed::fract_bits = 8;

// Constructors
// Default
Fixed::Fixed() : value(0) {}

// Copy
Fixed::Fixed(const Fixed& other) 
{
	this->value = other.getRawBits();
}

// With initial integer value
Fixed::Fixed(const int value)
{
	this->value = value << fract_bits;
}

// With initial floating point value
Fixed::Fixed(const float value)
{
	this->value = round(value * (1 << fract_bits));
}

// Operators
// Copy assignment operator
Fixed Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
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
	int64_t tmp_value = value;
	tmp_value *= other.value;
	tmp_value >>= fract_bits;
	Fixed tmp;
	tmp.setRawBits((int)tmp_value);
	return tmp;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	int64_t tmp_value = value;
	tmp_value <<= fract_bits;
	tmp_value /= other.value;
	Fixed tmp;
	tmp.setRawBits(tmp_value);
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
Fixed::~Fixed() {}

// Getter
int Fixed::getRawBits() const
{
	return value;
}

// Setter
void Fixed::setRawBits(int newValue)
{
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