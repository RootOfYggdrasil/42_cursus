

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	std::cout << "Default FragTrap is born!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	std::cout << "FragTrap " << name << " is ALIVE(?) YES INDEED!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	this->_maxHitPoints = copy.getMaxHitPoints();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructed ADDIO AMICI ADDIO" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " SGARELLAMI STO PENTA!" << std::endl;
}

void	FragTrap::attack(std::string const & target)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " is out of energy!" << std::endl;
	}		
}