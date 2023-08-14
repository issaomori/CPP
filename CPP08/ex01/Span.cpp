#include "Span.hpp"

Span::Span(unsigned int n) : max(n){
}

Span::~Span(){
}

Span::Span(const Span &copy) : max(copy.max){
    this->vect = copy.vect;
}

Span &Span::operator=(const Span &rhs){
    this->vect = rhs.vect;
    this->max = rhs.max;
    return *this;
}

unsigned int Span::getMax(void) const{
    return this->max;
}

const std::vector<int> &Span::getVect(void) const{
    return this->vect;
}

void Span::addNumber(int n){
    if (this->vect.size() == this->max)
        throw NotEnoughCapacity();
    this->vect.push_back(n);
}

unsigned int Span::shortestSpan(void){
    if (this->vect.size() < 2)
        throw InsufficientElements();
    std::vector<int> copy = this->vect;
    std::sort(copy.begin(), copy.end());
    unsigned int shortest = UINT_MAX;
    for (unsigned int i = 0; i < copy.size() - 1; i++) {
        if (copy[i + 1] - (unsigned)copy[i] < shortest)
            shortest = copy[i + 1] - copy[i];
    }
    return shortest;
}

unsigned int Span::longestSpan(void){
    if (this->vect.size() < 2)
        throw InsufficientElements();
    std::vector<int> copy = this->vect;
    std::sort(copy.begin(), copy.end());
    return copy[copy.size() - 1] - copy[0];
}

const char *Span::NotEnoughCapacity::what(void) const throw(){
    return "Not enough capacity";
}

const char *Span::InsufficientElements::what(void) const throw(){
    return "Insufficient elements";
}
