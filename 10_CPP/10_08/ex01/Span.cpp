
#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) { this->_v.reserve(n); }

Span::Span(Span const &other) {	*this = other; }

Span &Span::operator=(Span const &other)
{
	this->_n = other._n;
	this->_v = other._v;
	return *this;
}

Span::~Span(){}


void Span::addNumber(int number)
{
	if (this->_v.size() == this->_n)
		throw Span::FullSpanException();
	this->_v.push_back(number);
}

void Span::addNumber(int *begin, int *end)
{
	if (this->_v.size() + (end - begin) > this->_n)
		throw Span::FullSpanException();
	this->_v.insert(this->_v.end(), begin, end);
}

int Span::shortestSpan()
{
	if (this->_v.size() < 2)
		throw Span::NotEnoughNumbersException();
	std::vector<int> v = this->_v;
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (unsigned int i = 2; i < v.size(); i++)
	{
		if (v[i] - v[i - 1] < min)
			min = v[i] - v[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (this->_v.size() < 2)
		throw Span::NotEnoughNumbersException();
	std::vector<int> v = this->_v;
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}

const char *Span::FullSpanException::what() const throw()
{
	return "The span is full";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to calculate span";
}