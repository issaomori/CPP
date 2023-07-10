#include "HumanB.hpp"

HumanB::HumanB( void ){
}

HumanB::HumanB(std::string name){
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB( void ){
}

void HumanB::attack( void ){
    if (&this->_weapon->getType() == NULL){
        std::cout << "HumanB hasn't weapon." << std::endl;
        return;
    }
    std::cout << this->_name << " attacks with their weapon " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
    this->_weapon = &weapon;
}
