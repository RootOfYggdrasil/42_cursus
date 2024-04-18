
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat bobby;
	//std::cout << bobby;
	Bureaucrat b0("b0", 100);
	bobby = b0;
	std::cout << b0;
	b0.decrementGrade();

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
		Form form("SOTASSE", 40, 20);
		b0.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	
}