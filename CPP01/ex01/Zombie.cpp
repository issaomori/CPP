#include "Zombie.hpp"

Zombie::Zombie( void ){
}

void Zombie::setZombieName(std::string name){
    this->_name = name;
    std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie( void ){
    std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
}

void Zombie::announce( void ){
    std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
