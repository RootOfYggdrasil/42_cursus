
#ifndef RPN_HPP
#define RPN_HPP

#include "stdexcept"
#include "stack"
#include "sstream"
#include "iostream"
#include "cstdlib"

class RPN {
	private:
		const std::string	_setCharacter;
		RPN(const RPN&);
		RPN& operator=(const RPN&);
	public:
		RPN();
		~RPN();
		int	calculateRPN(std::string input);	

};

#endif