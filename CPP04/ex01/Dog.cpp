#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
    std::cout << "Default Dog Constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::~Dog(void){
    std::cout << "Dog Destructor called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog &name) : Animal("Dog"){
    std::cout << "Dog copy Constructor called" << std::endl;
    this->brain = new Brain(*name.getBrain());
    *this = name;
}

Dog &Dog::operator=(Dog const &name){
    std::cout << "Dog Copy Assignment Constructor called" << std::endl;
    if (this != &name){
        Brain* newBrain = new Brain(*name.getBrain());
        delete this->brain;
        this->brain = newBrain;
        this->type = name.getType();
    }
    return *this;
}

void Dog::makeSound(void) const{
    std::cout << "Au, Sniff, Au" << std::endl;
}

Brain* Dog::getBrain(void) const{
    return this->brain;
}
