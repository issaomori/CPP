#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &name){
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = name;
}

Animal &Animal::operator=(const Animal &name){
    this->type = name.getType();
    std::cout << "Animal Copy Assignment Constructor called" << std::endl;
}

std::string Animal::getType(void) const {
    return this->type;
}

void Animal::setType(std::string type){
    this->type = type;
}

void Animal::makeSound(void) const{
    std::cout << "Sound Emitted by the Animal" << std::endl;
}