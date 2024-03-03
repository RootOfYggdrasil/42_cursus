#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"


class HumanA
{
    private:
        std::string _name;
        const   Weapon& _weaponRef;
    public:
        HumanA(std::string  name, const Weapon& weapon);
        ~HumanA();
        void attack() const;
};


#endif