#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	std::cout << "---- Tests from subject ----" << std::endl;
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
/*
	std::cout << std::endl << "---- More tests ----" << std::endl;
	Fixed asd;
	asd.setRawBits(256);
	std::cout << "This should be 256: " << asd.getRawBits() << std::endl;*/

	return 0;
}