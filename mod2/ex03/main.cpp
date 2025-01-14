#include "Point.hpp"
#include <iostream>



void test(Point p)
{
	Point a = Point(0,0);
	Point b = Point(0, 10);
	Point c = Point(10, 0);

	bool inside = bsp(a, b, c, p);
	std::cout << "Point (" << p.getX() << "," << p.getY() << ") inside triangle: " << inside << std::endl;
}

int main(void)
{
	std::cout << "These are not inside:" << std::endl;
	test(Point(0, -9.99));
	test(Point(100, 100));
	test(Point(0,0));

	std::cout << "These are inside:" << std::endl;
	test(Point(1,1));
	test(Point(1.1,1.1));
	test(Point(1.9, 2.9));
	
	return 0;
}