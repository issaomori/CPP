#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(){
    std::cout << "ClapTrap Default constructor called" << std::endl;
    this->setName("FragTrap");
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "FragTrap " << this->getName() << " constucted"<< std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &name) : ClapTrap(name){
    *this = name;
    std::cout << "FragTrap copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &name){
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(name);
    return *this;
}

void FragTrap::highFivesGuys(void){
    if (this->getEnergyPoints() <= 0){
        std::cout << "FragTrap " << this->getName() << " is without energy"<< std::endl;
        return;
    }
    std::cout << "FragTrap " << this->getName() << " want to give high five"<< std::endl;
    this->setEnergyPoints(getEnergyPoints() - 1);
}