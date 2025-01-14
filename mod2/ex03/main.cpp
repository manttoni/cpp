#include "Point.hpp"
#include <iostream>



void test(Point p)
{
	Point a = Point(-1,0);
	Point c = Point(1, 2);
	Point b = Point(1, -1);

	bool inside = bsp(a, b, c, p);
	std::cout << "Point (" << p.getX() << "," << p.getY() << ") inside triangle: " << inside << std::endl;
}

int main(void)
{
	test(Point(0,0));
	test(Point(10, 10));

	return 0;
}