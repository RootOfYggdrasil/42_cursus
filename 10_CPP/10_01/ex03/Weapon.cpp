
#include "Weapon.hpp"

Weapon::Weapon(void) {return;}
Weapon::Weapon(std::string type) : _type(type) {return;}
Weapon::~Weapon(void) {return;}
const std::string &Weapon::getType(void) const {return this->_type;}
void Weapon::setType(std::string type) {this->_type = type; return;}