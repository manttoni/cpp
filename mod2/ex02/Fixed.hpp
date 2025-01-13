#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int fract_bits;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int value);
		Fixed(const float value);
		Fixed& operator=(const Fixed& other);
		bool operator>(const Fixed& other);
		bool operator<(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);
		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed& operator++();
		Fixed& operator--();
		~Fixed();

		int getRawBits() const;
		void setRawBits(int newValue);

		float toFloat(void) const;
		int toInt(void) const;

		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif