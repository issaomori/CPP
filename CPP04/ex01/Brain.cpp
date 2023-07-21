#include "Brain.hpp"

Brain::Brain(void){
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::~Brain(void){
    std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &name) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = name;
}

Brain &Brain::operator=(const Brain &name) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &name) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = name.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(std::string idea, int i){
    this->ideas[i] = idea;
}

std::string Brain::getIdea(int i) const {
    return this->ideas[i];
}