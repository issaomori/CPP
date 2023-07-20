#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
    std::cout << "Default Dog Constructor called" << std::endl;
}

Dog::~Dog(void){
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &name) : Animal("Dog"){
    std::cout << "Dog copy Constructor called" << std::endl;
    *this = name;
}

Dog &Dog::operator=(Dog const &name){
    this->type = name.getType();
    std::cout << "Dog Copy Assignment Constructor called" << std::endl;
    return *this;
}

void Dog::makeSound(void) const{
    std::cout << "Au, Sniff, Au" << std::cout;
}