#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(){
    std::cout << "ClapTrap Default constructor called" << std::endl;
    this->setName("ScavTrap");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << "ScavTrap" << this->getName() << "constucted"<< std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::~ScavTrap(void){
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &name){
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    this->setName(name.getName());
    this->setHitPoints(name.getHitPoints());
    this->setAttackDamage(name.getAttackDamage());
    this->setEnergyPoints(name.getEnergyPoints());
    return *this;
}

void ScavTrap::attack(const std::string& target){

    if (target.empty()){
        std::cout << "ScavTrap " << getName() << " Cannot attack because there is no target" << std::endl;
        return;
    }
    if(this->getEnergyPoints() <= 0){
        std::cout << "ScavTrap " << getName() << " Cannot attack because it has no EnergyPoints" << std::endl;
        return;
    }
    else if (this->getHitPoints() <= 0){
        std::cout << "ScavTrap " << getName() << " Cannot attack because it has no hp" << std::endl;
        return;
    }
    else{
        std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage"<< std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    }
}

void ScavTrap::guardGate(void){
    if (this->getHitPoints() <= 0)
        std::cout << "ScavTrap" << this->getName() << " can't guard gate because he's dead" << std::endl;
    else
        std::cout << "ScavTrap" << this->getName() << " is currently in gate keeper mode" << std::endl;
}
