#include "Point.hpp"
#include <cmath>

static float sideLength(Point& const a, Point& const b)
{
	float hor = a.getX() - b.getX();
	float ver = a.getY() - b.getY();
	return hypot(hor, ver);
}

static float calcTrianglePerimeter(Point& const a, Point& const b, Point& const c)
{
	float perimeter = sideLength(a, b) + sideLength(b, c) + sideLength(c, a);
	return perimeter;
}

static float calcTriangleArea(Point& const a, Point& const b, Point& const c)
{
	float s = calcTrianglePerimeter(a, b, c) / 2;
	return sqrt(s * (s - sideLenth(a, b)) * (s - sideLength(b, c)) * (s - sideLength(c, a)));
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