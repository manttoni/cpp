#include "Point.hpp"
#include <cmath>

static float sideLength(const Point& a, const Point& b)
{
	float hor = a.getX().toFloat() - b.getX().toFloat();
	float ver = a.getY().toFloat() - b.getY().toFloat();
	return hypot(hor, ver);
}

static float calcTrianglePerimeter(const Point& a, const Point& b, const Point& c)
{
	float perimeter = sideLength(a, b) + sideLength(b, c) + sideLength(c, a);
	return perimeter;
}

static float calcTriangleArea(const Point& a, const Point& b, const Point& c)
{
	float s = calcTrianglePerimeter(a, b, c) / 2;
	return sqrt(s * (s - sideLength(a, b)) * (s - sideLength(b, c)) * (s - sideLength(c, a)));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float area = calcTriangleArea(a, b, c);
	float areaA = calcTriangleArea(a, b, point);
	float areaB = calcTriangleArea(a, point, c);
	float areaC = calcTriangleArea(point, b, c);

	if (area * areaA * areaB * areaC == 0)
		return false;

	if (area != areaA + areaB + areaC)
		return false;

	return true;
}