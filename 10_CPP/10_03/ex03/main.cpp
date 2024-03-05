
#include	"DiamondTrap.hpp"

int		main(void)
{
	DiamondTrap	robot("GINETTO");
	DiamondTrap	robot2("Mario");
	//DiamondTrap	robot3();

	for (size_t i = 0; i < 105; i++)
		robot.attack("Pippo Duro");
	robot2.attack("Pippo Duro");

	
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
	
	robot.whoAmI();
	robot2.whoAmI();

	return (0);
}
