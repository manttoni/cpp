#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point& point) : x(point.x), y(point.y) {}

Point& Point::operator=(Point& point) const
{
	return point;
}

bool Point::operator==(const Point& point) const
{
	return this->x == point.getX() && this->y == point.getY();
}

const Fixed& Point::getX() const
{
	return x;
}

const Fixed& Point::getY() const
{
	return y;
}

Point::~Point() {}