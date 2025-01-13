#include "Point.hpp"
#include <iostream>

int main(void)
{
	Point a = Point(-10, -10);
	Point b = Point(10, -10);
	Point c = Point(0, 10);

	bool inside = bsp(a, b, c, Point(0, -9.99));

	std::cout << "Point inside triangle: " << inside << std::endl;
	return 0;
}