#include "Point.hpp"
#include <iostream>



void test(float x, float y)
{
	Point p = Point(x,y);
	Point a = Point(-1,0);
	Point c = Point(1, 2);
	Point b = Point(1, -1);

	bool inside = bsp(a, b, c, p);
	std::cout << "Point " << p << " inside triangle: " << inside << std::endl;
}

int main(void)
{
	test(0,0);
	test(-1,0);
	test(1,2);
	test(1,-1);

	test(10,10);
	test(-10,-10);
	test(0.1,0.1);
	test(-0.1,-0.1);
	test(2.2,2.2);

	return 0;
}