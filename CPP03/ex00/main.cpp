#include "ClapTrap.hpp"

// int	main(void)
// {
// 	ClapTrap	trap1;
// 	ClapTrap	trap2;

// 	trap1.setName("Rei Arthur");
//     trap2.setName("D. Sebastião");
// 	trap1.setAttackDamage(15);
// 	trap1.attack(trap2.getName());
// 	trap2.takeDamage(trap1.getAttackDamage());
// 	trap1.setAttackDamage(120);
// 	trap2.takeDamage(trap1.getAttackDamage());
	
// }

int main(void) {
  ClapTrap temp1;
  ClapTrap temp2("Reinaldo");
  ClapTrap clap1("Gianechini"), clap2(temp2);

  std::cout << "\n";

  clap1.setAttackDamage(1);
  clap2.setAttackDamage(1);

  clap1.attack(clap2.getName());
  clap2.takeDamage(clap1.getAttackDamage());
  clap2.beRepaired(1);
  std::cout << "\n";

  clap2.attack(clap1.getName());
  clap1.takeDamage(clap2.getAttackDamage());
  clap2.beRepaired(1);
  std::cout << "\n";

  clap1.setAttackDamage(10);
  clap2.setAttackDamage(10);

  clap1.attack(clap2.getName());
  clap2.takeDamage(clap1.getAttackDamage());
  clap2.beRepaired(1);
  std::cout << "\n";

  for (int i = 0; i < 8; i++) {
    clap1.beRepaired(1);
  }

  std::cout << "\n";

  clap1.attack(clap2.getName());
  clap2.takeDamage(clap1.getAttackDamage());
  clap2.attack(clap1.getName());

  std::cout << "\n";

  clap1.beRepaired(10);
  clap2.beRepaired(10);

  std::cout << "\n";

  return (0);
}
