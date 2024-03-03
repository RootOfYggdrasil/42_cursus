
#include <iostream>
#include <string>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*ptr = &brain;
	std::string	&ref = brain;


	std::cout << "String: " << brain << std::endl;
	std::cout << "Pointer: " << ptr << std::endl;
	std::cout << "Reference: " << ref << "\n" << std::endl;
	ref = "more Brain REF CHANGED";
	std::cout << "String: " << brain << std::endl;
	std::cout << "Pointer: " << ptr << std::endl;
	std::cout << "Reference: " << ref << "\n" << std::endl;
	brain = "brain CHANGED";
	std::cout << "String: " << brain << std::endl;
	std::cout << "Pointer: " << ptr << std::endl;
	std::cout << "Reference: " << ref << "\n" << std::endl;
}