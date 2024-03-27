
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = cat;
}

WrongCat &WrongCat::operator=(const WrongCat &cat) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &cat)
		this->_type = cat.getType();
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat sound" << std::endl;
}