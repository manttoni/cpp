#include "Point.hpp"

static Fixed signedArea(const Point& a, const Point& b, const Point& c)
{
	return Fixed(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = signedArea(a, b, c);
	Fixed areaPAB = signedArea(point, a, b);
	Fixed areaPBC = signedArea(point, b, c);
	Fixed areaPCA = signedArea(point, c, a);

	if (areaABC == 0 || areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
		return false;

	if ((areaABC > 0 && areaPAB > 0 && areaPBC > 0 && areaPCA > 0) ||
		(areaABC < 0 && areaPAB < 0 && areaPBC < 0 && areaPCA < 0))
	{
		return true;
	}

	return false;
}
