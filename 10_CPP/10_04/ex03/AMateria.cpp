
#include "AMateria.hpp"

AMateria::AMateria() : _type("Default") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &amateria) : _type(amateria.getType()) {}

AMateria &AMateria::operator=(const AMateria &amateria) {
	if (this != &amateria)
		this->_type = amateria.getType();
	return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter & target) {
	std::cout << "* uses " << this->getType() << " Materia on " << target.getName() << " *" << std::endl;
}