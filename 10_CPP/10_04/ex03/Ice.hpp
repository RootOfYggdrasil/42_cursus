
#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string.h>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &ice);
		Ice &operator=(const Ice &ice);
		virtual ~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
};


#endif