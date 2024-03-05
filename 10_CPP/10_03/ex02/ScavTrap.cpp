
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << " ScavTrap default  IS ALIVEEEEE" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << name << " ScavTrap IS ALIVEEEEE" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	//std::cout << "ScavTrap assignation operator" << std::endl;
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	this->_maxHitPoints = copy.getMaxHitPoints();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructed :'(" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode TI PROTEGGO RAGAZZO IDIOTA" << std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " is out of energy!" << std::endl;
	}		
}

