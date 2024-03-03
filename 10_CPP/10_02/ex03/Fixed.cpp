

#include "Fixed.hpp"

#pragma region Constructors and destructor
Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value) : _value(value << this->_fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << this->_fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
#pragma endregion

#pragma region Operators Overload

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy Assign operator called" << std::endl;
	if (this != &fixed)
		(this->_value) = fixed.getRawBits();
	return *this;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->getValue() > fixed.getValue());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->getValue() < fixed.getValue());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->getValue() >= fixed.getValue());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->getValue() <= fixed.getValue());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->getValue() == fixed.getValue());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->getValue() != fixed.getValue());
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

#pragma region Increment and Decrement operators

Fixed &Fixed::operator++()
{
	(this->_value)++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--()
{
	(this->_value)--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

#pragma endregion

#pragma region Min and Max functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

#pragma endregion


#pragma endregion


#pragma region Getters and Setters

int Fixed::getValue(void) const {return (this->_value);}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	(this->_value) = raw;
}

#pragma endregion


#pragma region Conversion functions

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_value) / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const
{
	return (this->_value) >> this->_fractionalBits;
}

#pragma endregion