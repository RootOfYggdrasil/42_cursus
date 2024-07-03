
#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN \"[RPN expression]\"" << std::endl;
		return 1;
	}
	RPN	rpn;
	try
	{
		std::cout << rpn.calculateRPN(av[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error" << std::endl;
	}
	return 0;
}

