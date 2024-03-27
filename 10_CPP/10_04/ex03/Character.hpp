
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string.h>
# include <iostream>
# include "AMateria.hpp"

class	Character : public ICharacter
{
	private:
		AMateria*	_inventory[4];
		AMateria*	_floorMateria[1024];
		std::string	_name;
	public:
		Character();
		Character(const Character &character);
		Character(std::string const & name);
		Character &operator=(const Character &character);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
