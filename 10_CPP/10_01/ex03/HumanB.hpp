#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {

public:
	HumanB(void);
	HumanB(std::string name);
	~HumanB(void);
	void setName(std::string name);
	const std::string &getName(void) const;
	void attack(void);
	void setWeapon(Weapon &weapon);
private:
	std::string _name;
	Weapon *_weapon;
};

#endif