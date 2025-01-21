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
	std::cout << "---- These are the corners of the triangle ----" << std::endl;
	test(-1,0);
	test(1,2);
	test(1,-1);

	std::cout << "---- These are far away ----" << std::endl;
	test(10,10);
	test(-10,-10);
	test(10,-10);
	test(-10, 10);
	test(100.1, -100.1);
	test(-50.4, -123.2);

	std::cout << "--- These are very close but outside ----" << std::endl;
	test(-1.1f,0.1f);
	test(1.1f, 0);
	test(1, -1.1);

	std::cout << "---- These are very close but inside ----" << std::endl;
	test(-0.09f,0);
	test(0, 0.09f);
	test(0.09f, 0);

	std::cout << "---- These are clearly inside ----" << std::endl;
	test(0,0);
	test(0.5f, 0.5f);
	test(0.1f, 0.1f);
	return 0;
}