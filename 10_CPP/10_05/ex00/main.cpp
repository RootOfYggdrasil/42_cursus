
#include "Bureaucrat.hpp"

int main()
{
		Bureaucrat bobby;
	std::cout << bobby;
	Bureaucrat b0("b0", 1);
	bobby = b0;
	std::cout << "bobbyyyyy " << bobby;
	/*std::cout << b0;
	b0.decrementGrade();
	std::cout << b0;
	b0.decrementGrade();
	std::cout << b0;
	b0.decrementGrade();
	std::cout << b0;
	b0.incrementGrade();
	std::cout << b0;
	b0.incrementGrade();
	std::cout << b0;*/
	try
	{
		/*Bureaucrat b1("b1", 1);
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;*/
		Bureaucrat b2("b2", 150);
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
		b2.incrementGrade();
		std::cout << b2;
		b2.incrementGrade();
		std::cout << b2;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	
}