
#ifndef	POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;
public:
	#pragma region Ortodox Canonical Form
	Point();
	Point(const Point &point);
	~Point();
	Point &operator=(const Point &point);
	#pragma endregion
	Point(const float x,const float y);
	Point(const Fixed x,const Fixed y);
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif