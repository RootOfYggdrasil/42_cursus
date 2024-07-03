
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void addNumber(int *begin, int *end);

		class FullSpanException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class NotEnoughNumbersException : public std::exception
		{
			virtual const char *what() const throw();
		};
};


#endif