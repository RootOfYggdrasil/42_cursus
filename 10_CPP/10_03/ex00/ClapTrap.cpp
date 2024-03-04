
#include "ClapTrap.hpp"

#pragma region Constructors and Destructors

ClapTrap::ClapTrap() : _name("Default ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap is born!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "ClapTrap " << this->_name << " is born!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this == &copy)
		return *this;
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
}


#pragma endregion


#pragma region Getters

std::string	ClapTrap::getName() const
{
	return this->_name;
}

int	ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

int	ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

int	ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

#pragma endregion