
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &dog)
		this->_type = dog.getType();
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Bark, but angry BARK, RUN, BARK BARK BARK" << std::endl;
}
