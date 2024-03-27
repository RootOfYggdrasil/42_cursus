
#include "Character.hpp"

Character::Character() : _name("Default") {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 1024; i++)
		this->_floorMateria[i] = NULL;
}

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 1024; i++)
		this->_floorMateria[i] = NULL;
}

Character::Character(const Character &character) : _name(character.getName()) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = character._inventory[i];
	for (int i = 0; i < 1024; i++)
		this->_floorMateria[i] = NULL;
}

Character &Character::operator=(const Character &character) {
	if (this != &character) 
	{
		this->_name = character.getName();
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = character._inventory[i];
		for (int i = 0; i < 1024; i++)
			this->_floorMateria[i] = NULL;
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	for (int i = 0; i < 1024; i++) {
		if (this->_floorMateria[i] != NULL)
			delete this->_floorMateria[i];
	}
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
	{
		for (int i = 0; i < 1024; i++)
		{
			if (this->_floorMateria[i] == NULL)
			{
				this->_floorMateria[i] = this->_inventory[idx];
				this->_inventory[idx] = NULL;
				break;
			}
		}
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}
