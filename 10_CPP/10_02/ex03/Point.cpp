
#include "Point.hpp"


#pragma region Constructors and destructor

Point::Point() : _x(0), _y(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point &point) : _x(point.getX()), _y(point.getY())
{
	//std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
	//std::cout << "Destructor called" << std::endl;
}

Point::Point(const float x,const float y) : _x(x), _y(y)
{
	//std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Fixed x,const Fixed y) : _x(x), _y(y)
{
	//std::cout << "Fixed constructor called" << std::endl;
}

Point &Point::operator=(const Point &point)
{
	//std::cout << "Assignation operator called" << std::endl;
	if (this == &point)
		return *this;
	*this = point;
	return *this;
}

#pragma endregion

#pragma region Getters

Fixed Point::getX() const
{
	return this->_x;
}

Fixed Point::getY() const
{
	return this->_y;
}

#pragma endregion
