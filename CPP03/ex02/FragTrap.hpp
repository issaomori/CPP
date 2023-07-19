#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap();
        ~FragTrap();

        FragTrap(std::string name);
        FragTrap(FragTrap const &name);
        FragTrap &operator=(FragTrap const &name);
    
        void highFivesGuys(void);

};

#endif