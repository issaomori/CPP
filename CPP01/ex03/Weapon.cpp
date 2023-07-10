#include "Weapon.hpp"

Weapon::Weapon(){
}

Weapon::Weapon(std::string _private_str){
    this->setType(_private_str);
}

Weapon::~Weapon( void ){
}

const std::string &Weapon::getType( void ){
    return (this->type);
}

void Weapon::setType(std::string newStr){
    this->type = newStr;
}
