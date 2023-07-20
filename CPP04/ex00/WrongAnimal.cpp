#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal"){
    std::cout << "Default WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void){
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type){
    std::cout << "Wrong Animal Constructor called for" << type << std::endl;
    this->setType(type);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &name){
    this->type = name.getType();
    std::cout << "Wrong Animal Copy Assignment Constructor called" << std::endl;
    return *this;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "Wrong Animal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const{
    return this->type;
}

void WrongAnimal::setType(std::string type){
    this->type = type;
}
