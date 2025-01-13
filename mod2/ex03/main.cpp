#include "Point.hpp"
#include <iostream>

int main(void)
{
	Point a = Point(0, 0);
	Point b = Point(10, 10);
	Point c = Point(10, 0);

	std::cout << "True or no: " << bsp(a, b, c, Point(2, 1)) << std::endl;
	return 0;
}