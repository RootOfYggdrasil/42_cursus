
#include	"Zombie.hpp"

int	main(void)
{
	int	numZombies = 71;
	std::string	zombieName = "hordeeeeee";

	Zombie *horde = zombieHorde(numZombies, zombieName); 
    for (int i = 0; i < numZombies; ++i) {
        std::cout << i << ") ";
        horde[i].announce();
    }
    delete[] horde;

    return (0);
}