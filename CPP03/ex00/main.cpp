#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	trap1;
	ClapTrap	trap2("Adolf hitler");

	trap1.setName("Trap 1");
	trap1.setAttackDamage(-5);
	trap1.attack("trap2");
	trap2.takeDamage(trap1.getAttackDamage());
	trap1.setAttackDamage(120);
	trap2.takeDamage(trap1.getAttackDamage());
	
}