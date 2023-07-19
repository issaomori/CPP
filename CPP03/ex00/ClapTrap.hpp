#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap{
    private:
    std::string name;
    int hp;
    int energy_points;
    int attack_damage;

    public:
    ClapTrap(void);
    ~ClapTrap(void);

    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &name);
    ClapTrap &operator=(ClapTrap const &name);

    std::string getName(void) const;
    int getHitPoints(void) const;
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;

    void setName(std::string name);
    void setHitPoints(int hp);
    void setEnergyPoints(int energy_points);
    void setAttackDamage(int attack);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);


};

#endif