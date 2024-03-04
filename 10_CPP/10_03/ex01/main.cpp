
#include	"ClapTrap.hpp"

int		main(void)
{
	ClapTrap	robot("ClapTrap");
	ClapTrap	robot2("ClapTrap2");
	ClapTrap	robot3();

	for (size_t i = 0; i < 12; i++)
		robot.attack("Pippo Duro");
	
	robot.takeDamage(9);
	std::cout << robot.getName() << " : Hitpoints " << robot.getHitPoints() << std::endl;
	robot.takeDamage(9);
	std::cout << robot.getName() << " : Hitpoints " << robot.getHitPoints() << std::endl;
	robot.beRepaired(10);
	std::cout << robot.getName() << " : Hitpoints " << robot.getHitPoints() << std::endl;
	robot2.beRepaired(10);
	std::cout << robot2.getName() << " : Hitpoints " << robot2.getHitPoints() << std::endl;
	robot2.takeDamage(11);
	std::cout << robot2.getName() << " : Hitpoints " << robot2.getHitPoints() << std::endl;	
	
	return (0);
}
