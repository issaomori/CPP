#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat"){
    std::cout << "Default Cat constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::~Cat(void){
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

Cat::Cat(Cat const &name) : AAnimal("Cat"){
    std::cout << "Cat Copy Constructor called" << std::endl;
    this->brain = new Brain(*name.getBrain());
    *this = name;
}

Cat &Cat::operator=(const Cat &name){
    std::cout << "Cat Copy Assignment Operator called" << std::endl;
    if (this != &name){
        Brain* newBrain = new Brain(*name.getBrain());
        delete this->brain;
        this->brain = newBrain;
        this->type = name.getType();
    }
    // if (this->brain)
    //     delete this->brain;
    return *this;
}

void Cat::makeSound(void) const{
    std::cout <<"Meow" << std::endl;
}

Brain* Cat::getBrain(void) const{
    return this->brain;
}
