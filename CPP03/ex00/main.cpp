#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	trap1;
	ClapTrap	trap2;

	trap1.setName("Rei Arthur");
    trap2.setName("D. Sebastião");
	trap1.setAttackDamage(15);
	trap1.attack(trap2.getName());
	trap2.takeDamage(trap1.getAttackDamage());
	trap1.setAttackDamage(120);
	trap2.takeDamage(trap1.getAttackDamage());
	
}