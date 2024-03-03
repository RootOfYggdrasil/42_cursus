
#include "HumanA.hpp"

HumanA::HumanA(std::string name, const Weapon& weapon) : _name(name), _weaponRef(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const
{
    std::cout << _name << " attacks with their " << _weaponRef.getType() << std::endl;
}