#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    std::cout << "---- Tests from subject ----" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "---- Testing increments/decrements ----" << std::endl;
    Fixed asd1 = Fixed(0);
    Fixed asd2 = Fixed(1);
    // asd1 = 0, asd2 = 1
    std::cout << "Should be 0 + ~1.0039 = ~1.0039: " << asd1++ + ++asd2 << std::endl;
    // asd1 = 0.0039, asd2 = 1.0039
    std::cout << "Should be ~0.0078 + ~1.0039 = ~1.0117: " <<  ++asd1 + asd2++ << std::endl;
    // asd1 = 0.0078, asd2 = 1.0078
    std::cout << "Should be ~0.0078 + ~1.0039 = ~1.0117:" << asd1-- + --asd2 << std::endl;
    // asd1 = 0.0039, asd2 = 1.0039
    std::cout << "Should be 0 + ~1.0039 = ~1.0039: " << --asd1 + asd2-- << std::endl;
    std::cout << "Should be 0 + 1: " << asd1 + asd2 << std::endl;

    std::cout << "---- Testing multi/divi ----" << std::endl;
    Fixed qwe1 = Fixed(8);
    Fixed qwe2 = Fixed(4);
    std::cout << "8 * 4 = " << qwe1 * qwe2 << std::endl;
    std::cout << "8 * 8 = " << qwe1 * qwe1 << std::endl;
    std::cout << "8 / 4 = " << qwe1 / qwe2 << std::endl;
    std::cout << "8 / 8 = " << qwe1 / qwe1 << std::endl;

    std::cout << "---- Same with floats ----" << std::endl;
    Fixed zxc1 = Fixed(8.7f);
    Fixed zxc2 = Fixed(4.5f);
    std::cout << "8.7 * 4.5 = 39.15: " << zxc1 * zxc2 << std::endl;
    std::cout << "8.7 * 8.7 = 75.69 " << zxc1 * zxc1 << std::endl;
    std::cout << "8.7 / 4.5 = 1.93: " << zxc1 / zxc2 << std::endl;
    std::cout << "8.7 / 8.7 = 1: " << zxc1 / zxc1 << std::endl;

    std::cout << "---- Testing sum/sub ----" << std::endl;
    Fixed rty1 = Fixed(8);
    Fixed rty2 = Fixed(4);
    std::cout << "8 + 4 = " << rty1 + rty2 << std::endl;
    std::cout << "8 + 8 = " << rty1 + rty1 << std::endl;
    std::cout << "8 - 4 = " << rty1 - rty2 << std::endl;
    std::cout << "8 - 8 = " << rty1 - rty1 << std::endl;

    std::cout << "---- Same with floats ----" << std::endl;
    Fixed vbn1 = Fixed(8.7f);
    Fixed vbn2 = Fixed(4.5f);
    std::cout << "8.7 + 4.5 = 13.2: " << vbn1 + vbn2 << std::endl;
    std::cout << "8.7 + 8.7 = 17.4: " << vbn1 + vbn1 << std::endl;
    std::cout << "8.7 - 4.5 = 4.2: " << vbn1 - vbn2 << std::endl;
    std::cout << "8.7 - 8.7 = 0: " << vbn1 - vbn1 << std::endl;
    return 0;
}