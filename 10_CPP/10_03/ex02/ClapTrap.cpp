
#include "ClapTrap.hpp"

#pragma region Constructors and Destructors

ClapTrap::ClapTrap() : _name("Default ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHitPoints(10)
{
	std::cout << "Default ClapTrap is born!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHitPoints(10)
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
	this->_maxHitPoints = copy.getMaxHitPoints();
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " is Deconstructed!" << std::endl;
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

int	ClapTrap::getMaxHitPoints() const
{
	return this->_maxHitPoints;
}

#pragma endregion

void	ClapTrap::attack(std::string const & target)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
	}		
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if(this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints = (int)(this->_hitPoints - amount) < 0 ? 0 : this->_hitPoints - amount;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		std::cout << this->_name << " is repaired for " << amount << " points!" << std::endl;
		this->_hitPoints = (this->_hitPoints + amount) > this->_maxHitPoints ? this->_maxHitPoints : this->_hitPoints + amount;
	}
	else
	{
		std::cout << this->_name << " is already dead!" << std::endl;
	}
}