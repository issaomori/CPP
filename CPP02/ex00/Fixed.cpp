#include "Fixed.hpp"

Fixed::Fixed( void ){
    std::cout << "Default constructor called" << std::endl;
    _raw_bits = 0;
}

Fixed::~Fixed( void ){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed){
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return _raw_bits;
}

Fixed &Fixed::operator = (const Fixed &fixed){
    std::cout << "Copy assignment operator called" << std::endl;
    _raw_bits = fixed.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    _raw_bits = raw;
}
 