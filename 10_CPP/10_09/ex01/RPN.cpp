
#include "RPN.hpp"

RPN::RPN() : _setCharacter("/*-+") { }

RPN::~RPN() { }

int	calculateOperation(char op, int a, int b)
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw std::exception();
			return (a / b);
		default:
			throw std::exception();
	}
	return 0;
}

int	RPN::calculateRPN(std::string input)
{
	std::stack<int>	stack;
	std::stringstream	ss(input);
	std::string		token;
	int			a;
	int			b;

	while (ss >> token)
	{
		if (token.size() == 1 && this->_setCharacter.find(token[0]) != std::string::npos)
		{
			if (stack.size() < 2)
				throw std::exception();
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			stack.push(calculateOperation(token[0], a, b));
		}
		else
		{
			try
			{
				stack.push(std::atoi(token.c_str()));
			}
			catch (std::exception &e)
			{
				throw std::exception();
			}
		}
	}
	if (stack.size() != 1)
		throw std::exception();
	return stack.top();
}