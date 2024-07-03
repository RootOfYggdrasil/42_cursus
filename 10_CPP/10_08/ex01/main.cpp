
#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	int sp2[] = {10,14,15};

	sp.addNumber(7);
	sp.addNumber(3);
	sp.addNumber(4);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(sp2, sp2 + sizeof(sp2) / sizeof(*sp2));
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
