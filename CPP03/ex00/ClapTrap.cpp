#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hp(10), stamina(10), hit(0){
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void){
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), stamina(10), hit(0){
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
    this->hit = name.hit;
    this->stamina = name.stamina;
    return *this;
}

std::string ClapTrap::getName(void) const{
    return this->name;
}

int ClapTrap::getHp(void) const{
    return this->hp;
}

int ClapTrap::getStamina(void) const{
    return this->stamina;
}

int ClapTrap::getHit(void) const{
    return this->hit;
}

void ClapTrap::setName(std::string name){
    this->name = name;
}

void ClapTrap::setHp(int hp) const{
    this->hp = hp;
}

void ClapTrap::setStamina(int stamina) const{
    this->stamina = stamina;
}

void ClapTrap::setHit(int hit) const{
    this->hit = hit;
}

void ClapTrap::attack(const std::string& target){

    if (target.empty()){
        std::cout << "ClapTrap " << getName() << " Cannot attack because there is no target" << std::endl;
        return;
    }
    if(this->getStamina() <= 0){
        std::cout << "ClapTrap " << getName() << " Cannot attack because it has no stamina" << std::endl;
        return;
    }
    else if (this->getHp() <= 0){
        std::cout << "ClapTrap " << getName() << " Cannot attack because it has no hp" << std::endl;
        return;
    }
    else
        std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getHit() << " points of damage"<< std::endl;
        this->stamina--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->getHp() == 0){
        std::cout << "ClapTrap " << this->getName() << " is dead" << std::endl;
        return;
    }else
        std::cout << "ClapTrap " << this->getName() << " takes " << amount << " damage" <<std::endl;
    if(this->getHit() <= amount)
        this->getHit() = 0;
    else
    this->getHit() -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->getHp() == 0){
        std::cout << "ClapTrap " << this->getName() << " is dead" << std::endl;
        return;
    }else if (this->getStamina() < 1){
        std::cout << "ClapTrap " << this->getName() << " It cannot be repaired because it has no energy" << std::endl;
        return;
    }else{

        std::cout << "ClapTrap " << this->getName() << " is repairing himself " << amount << " Hp"<< std::endl;
        this->setHp(this->getHp() + amount);
        this->setStamina(this->getStamina() -1);
    }
}