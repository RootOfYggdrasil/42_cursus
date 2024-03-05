

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(const FragTrap &copy);
	~FragTrap();
	void	highFivesGuys();
	void	attack(std::string const & target);
};


#endif