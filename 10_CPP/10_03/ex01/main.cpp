
#include	"ScavTrap.hpp"

int		main(void)
{
	ScavTrap	robot("GINO");
	ScavTrap	robot2("Pepperiello");
	ScavTrap	robot3();

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
