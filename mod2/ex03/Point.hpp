#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& point);

		Point& operator=(Point& point) const;
		bool operator==(const Point& point) const;

		const Fixed& getX() const;
		const Fixed& getY() const;

		~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif