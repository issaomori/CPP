#include "ScavTrap.hpp"

// int main(void) {
//   ClapTrap clap("Jonas");
//   ScavTrap scav("Brothers");

//   std::cout << "\n";

//   clap.attack(scav.getName());
//   scav.takeDamage(clap.getAttackDamage());
//   scav.guardGate();
//   scav.beRepaired(1);
//   std::cout << "\n";

//   scav.attack(clap.getName());
//   clap.takeDamage(scav.getAttackDamage());
//   scav.guardGate();
//   scav.beRepaired(1);
//   std::cout << "\n";

//   clap.attack(scav.getName());
//   scav.takeDamage(clap.getAttackDamage());
//   scav.guardGate();
//   scav.beRepaired(1);
//   std::cout << "\n";

//   clap.beRepaired(1);

//   std::cout << "\n";

//   clap.attack(scav.getName());
//   scav.takeDamage(clap.getAttackDamage());
//   scav.attack(clap.getName());

//   std::cout << "\n";

//   clap.beRepaired(10);
//   scav.beRepaired(10);

//   std::cout << "\n";

//   return (0);
// }

int main() {
    ClapTrap clap("Jonas");
    ScavTrap scav("Brothers");

    std::cout << "\n";

    clap.attack(scav.getName());
    scav.takeDamage(clap.getAttackDamage());
    scav.guardGate();
    scav.beRepaired(1);
    std::cout << "\n";

    scav.attack(clap.getName());
    clap.takeDamage(scav.getAttackDamage());
    scav.guardGate();
    scav.beRepaired(1);
    std::cout << "\n";

    clap.attack(scav.getName());
    scav.takeDamage(clap.getAttackDamage());
    scav.guardGate();
    scav.beRepaired(1);
    std::cout << "\n";

    clap.beRepaired(1);
    std::cout << "\n";

    clap.attack(scav.getName());
    scav.takeDamage(clap.getAttackDamage());
    scav.attack(clap.getName());
    std::cout << "\n";

    clap.beRepaired(10);
    scav.beRepaired(10);
    std::cout << "\n";

    return 0;
}