#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    private:
    std::string name;
    int hp;
    int stamina;
    int hit;

    public:
    ClapTrap(void);
    ~ClapTrap(void);

    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &name);
    ClapTrap &operator=(ClapTrap const &name);

    std::string getName(void) const;
    int getHp(void) const;
    int getStamina(void) const;
    int getHit(void) const;

    void setName(std::string name);
    void setHp(void) const;
    void setStamina(void) const;
    void setHit(void) const;

    bool ClapTrap::isDead() const;
    bool ClapTrap::isOutOfStamina() const;
    bool ClapTrap::decreaseStamina() const;

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif