#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hp(10), energy_points(10), attack_damage(0){
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void){
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy_points(10), attack_damage(0){
    std::cout << "ClapTrap Parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &name){
    *this = name;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &name){
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    this->name = name.name;
    this->hp = name.hp;
    this->attack_damage = name.attack_damage;
    this->energy_points = name.energy_points;
    return *this;
}

std::string ClapTrap::getName(void) const{
    return this->name;
}

int ClapTrap::getHitPoints(void) const{
    return this->hp;
}

int ClapTrap::getEnergyPoints(void) const{
    return this->energy_points;
}

int ClapTrap::getAttackDamage(void) const{
    return this->attack_damage;
}

void ClapTrap::setName(std::string name){
    this->name = name;
}

void ClapTrap::setHitPoints(int hp){
    if (hp < 0)
        this->hp = 0;
    this->hp = hp;
}

void ClapTrap::setEnergyPoints(int energy){
    if (energy < 0)
        this->energy_points = 0;
    this->energy_points = energy;
}

void ClapTrap::setAttackDamage(int attack){
    if (attack < 0)
        this->attack_damage = 0;
    this->attack_damage = attack;
}

void ClapTrap::attack(const std::string& target){

    if (target.empty()){
        std::cout << "ClapTrap " << getName() << " Cannot attack because there is no target" << std::endl;
        return;
    }
    if(this->getEnergyPoints() <= 0){
        std::cout << "ClapTrap " << getName() << " Cannot attack because it has no EnergyPoints" << std::endl;
        return;
    }
    else if (this->getHitPoints() <= 0){
        std::cout << "ClapTrap " << getName() << " Cannot attack because it has no hp" << std::endl;
        return;
    }
    else{
        std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage"<< std::endl;
        this->energy_points--;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->getHitPoints() == 0){
        std::cout << "ClapTrap " << this->getName() << " is dead" << std::endl;
        return;
    }else
        std::cout << "ClapTrap " << this->getName() << " takes " << amount << " damage" <<std::endl;
    if(this->getAttackDamage() <= (int)amount)
        this->setAttackDamage(0);
    else
    this->setAttackDamage(getAttackDamage() - amount);
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->getHitPoints() == 0){
        std::cout << "ClapTrap " << this->getName() << " is dead" << std::endl;
        return;
    }else if (this->getEnergyPoints() < 1){
        std::cout << "ClapTrap " << this->getName() << " It cannot be repaired because it has no energy" << std::endl;
        return;
    }else{

        std::cout << "ClapTrap " << this->getName() << " is repairing himself " << amount << " Hp"<< std::endl;
        this->setHitPoints(this->getHitPoints() + amount);
        this->setEnergyPoints(this->getEnergyPoints() -1);
    }

}