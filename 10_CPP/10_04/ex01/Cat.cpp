

#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &cat) {
		_type = cat.getType();
		delete _brain;
		_brain = new Brain(*cat.getBrain());
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "Meow, but angry MEOW, RUN, MEOW MEOW MEOW" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->_brain;
}

void Cat::setIdea(int index, std::string idea) {
	_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
	return _brain->getIdea(index);
}