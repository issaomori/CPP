#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"){
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::~Cat(void){
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &name) : Animal("Cat"){
    std::cout << "Cat Copy Constructor called" << std::endl;
    *this = name;
}

Cat &Cat::operator=(const Cat &name){
    this->type = name.getType();
    std::cout << "Cat Copy Assignment Operator called" << std::endl;
    return *this;
}

void Cat::makeSound(void) const{
    std::cout <<"Meow" << std::endl;
}
