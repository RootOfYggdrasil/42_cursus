
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog){
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*dog.getBrain());
}

Dog &Dog::operator=(const Dog &dog) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &dog)
	{
		this->_type = dog.getType();
		delete _brain;
		_brain = new Brain(*dog.getBrain());
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "Bark, but angry BARK, RUN, BARK BARK BARK" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->_brain;
}

void Dog::setIdea(int index, std::string idea) {
	_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
	return _brain->getIdea(index);
}