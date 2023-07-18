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

void ClapTrap::setHp(void) const{
    this->hp = hp;
}

void ClapTrap::setStamina(void) const{
    this->stamina = stamina;
}

void ClapTrap::setHit(void) const{
    this->hit = hit;
}

bool ClapTrap::isDead() const {
    return getHp() == 0;
}

bool ClapTrap::isOutOfStamina() const {
    return getStamina() == 0;
}

bool ClapTrap::decreaseStamina() const {
    setStamina(getStamina() - 1) == 0;
}

void ClapTrap::attack(const std::string& target){
    if(isDead())
        std::cout << getName() << "cannot attack because he is dead" << std::endl;
    else if (isOutOfStamina())
        std::cout << getName() << "cannot attack because he is out of stamina" << std::endl;
    else
        std::cout << getName() << " attacks " << target << ", causing " << getHit() << " points of damage"<< std::endl;
        decreaseStamina();
}

void ClapTrap::takeDamage(unsigned int amount){
}

void ClapTrap::beRepaired(unsigned int amount){
    
}