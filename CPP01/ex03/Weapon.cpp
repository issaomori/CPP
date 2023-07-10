#include "Weapon.hpp"

Weapon::Weapon(std::string _private_str){
    this->setType(_private_str);
}

Weapon::~Weapon(){
    std::cout << "Weapon destructor called" << std::endl;
}

const std::string &Weapon::getType( void ){
    return (this->_private_str);
}

void Weapon::setType(std::string newStr){
    this->_private_str = newStr;
}
