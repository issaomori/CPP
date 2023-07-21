#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal"){
    std::cout << "AAnimal Default Constructor called" << std::endl;
}

AAnimal::~AAnimal(void){
    std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &name){
    std::cout << "AAnimal Copy Constructor called" << std::endl;
    *this = name;
}

AAnimal::AAnimal(std::string const type){
    std::cout << "AAnimal Constructor called " << type << std::endl;
    this->setType(type);
}

AAnimal &AAnimal::operator=(const AAnimal &name){
    this->type = name.getType();
    std::cout << "AAnimal Copy Assignment Constructor called" << std::endl;
    return *this;
}

std::string AAnimal::getType(void) const {
    return this->type;
}

void AAnimal::setType(std::string type){
    this->type = type;
}

void AAnimal::makeSound() const{
    std::cout << "Sound Emitted by the Animal" << std::endl;
}
