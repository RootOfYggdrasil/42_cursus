
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = "Default DiamondTrap";
	_hitPoints = FragTrap::getHitPoints();
	_energyPoints = ScavTrap::getEnergyPoints();
	_attackDamage = FragTrap::getAttackDamage();
	ClapTrap::_name = "Default _clap_name";
	std::cout << "Default DiamondTrap is born, SHINEEEEE ON YOUR CRAZY DIAMONDDDD!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	_hitPoints = FragTrap::getHitPoints();
	_energyPoints = ScavTrap::getEnergyPoints();
	_attackDamage = FragTrap::getAttackDamage();
	ClapTrap::_name = name + "_clap_name";
	std::cout << "DiamondTrap " << name << " is born, SHINEEEEE ON YOUR CRAZY DIAMONDDDD!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	*this = copy;
	std::cout << "DiamondTrap " << this->_name << " is born, SHINEEEEE ON YOUR CRAZY DIAMONDDDD!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
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

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " is Melted, Jet Fuel Can't Melt Steel Beams!" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "PERCHE IO SONO " << this->_name << " and my ClapTrap name is " << this->ClapTrap::getName() << " E VOI NON SIETE UN CAZZO !!!" << std::endl;
}