
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weaponPtr(nullptr) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon)
{
    _weaponPtr = &weapon;
}

void HumanB::attack() const
{
    if (_weaponPtr)
        std::cout << _name << " attacks with their " << _weaponPtr->getType() << std::endl;
    else
        std::cout << _name << " attacks with HO I PUGNI NELLE MANI, PUGNO DI POLLICE " << std::endl;
}