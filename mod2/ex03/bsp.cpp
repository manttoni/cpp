#include "Point.hpp"
#include <iostream>

static Fixed areaSign(const Point& a, const Point& b, const Point& c)
{
	Fixed areaSign = Fixed(a.getX() * (b.getY() - c.getY()) 
						+ b.getX() * (c.getY() - a.getY())
						+ c.getX() * (a.getY() - b.getY()));

	std::cout << "Points:" << std::endl;
	std::cout << "a: (" << a.getX() << " , " << a.getY() << ")" << std::endl;
	std::cout << "b: (" << b.getX() << " , " << b.getY() << ")" << std::endl;
	std::cout << "c: (" << c.getX() << " , " << c.getY() << ")" << std::endl;
	std::cout << "areaSign: " << areaSign << std::endl;

	return areaSign;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = areaSign(a, b, c);
	Fixed areaPAB = areaSign(point, a, b);
	Fixed areaPBC = areaSign(point, b, c);
	Fixed areaPCA = areaSign(point, c, a);

	if (areaABC == 0 || areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
		return false;

	if ((areaABC > 0 && areaPAB > 0 && areaPBC > 0 && areaPCA > 0) ||
		(areaABC < 0 && areaPAB < 0 && areaPBC < 0 && areaPCA < 0))
	{
		return true;
	}

	return false;
}
