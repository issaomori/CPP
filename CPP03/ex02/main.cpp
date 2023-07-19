#include "FragTrap.hpp"

int main() {
    ClapTrap clap("Serginho Malandro");
    ScavTrap scav("Dr. Gutierrez");
    FragTrap frag("Paulo Plinio");

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

    frag.attack(clap.getName());
    clap.takeDamage(frag.getAttackDamage());
    frag.highFivesGuys();

    std::cout << "\n";

    clap.attack(frag.getName());
    frag.takeDamage(clap.getAttackDamage());
    frag.highFivesGuys();

    std::cout << "\n";

    return 0;
}