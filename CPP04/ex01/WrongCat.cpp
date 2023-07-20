#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat"){
    std::cout << "Default WrongCat Constructor called" << std::endl;
}

WrongCat::~WrongCat(void){
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &name) : WrongAnimal("WrongCat"){
    std::cout << "WrongCat Copy Constructor called" << std::endl;
    *this = name;
}

WrongCat &WrongCat::operator=(const WrongCat &name){
    this->type = name.getType();
    std::cout << "WrongCat Copy Assignment Operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound(void) const{
    std::cout << "iau iau" << std::endl;
}
