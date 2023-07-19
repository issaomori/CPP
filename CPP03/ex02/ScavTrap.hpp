#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
    ScavTrap();
    ~ScavTrap();

    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &name);
    ScavTrap &operator=(ScavTrap const &name);

    void attack(const std::string &target);
    void guardGate(void);
};

#endif