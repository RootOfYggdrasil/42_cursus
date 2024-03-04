
#include <iostream>
#include "Point.hpp"


int	main( void ) {
	Point a(0, 0);
	Point b(Fixed(0.5f), Fixed(10.10f));
	Point c(10.10f, 0.57f);

	std::cout << "Point a: " << a.getX() << ", " << a.getY() << std::endl;
	std::cout << "Point b: " << b.getX() << ", " << b.getY() << std::endl;
	std::cout << "Point c: " << c.getX() << ", " << c.getY() << std::endl;
	std::cout << "Point status: " << bsp(a, b, c, Point(1, 1)) << std::endl;
	std::cout << "Point status: " << bsp(a, b, c, Point(10.08f, 0.57f)) << std::endl;
	std::cout << "Point status: " << bsp(a, b, c, Point(0, 0)) << std::endl;

	return 0;
}