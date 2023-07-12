#include "Fixed.hpp"

Fixed::Fixed( void ){
    std::cout << "Default constructor called" << std::endl;
    fixed_number_point = 0;
}

Fixed::~Fixed( void ){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed){
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int number){
    std::cout << "Int constructor called" << std::endl;
    fixed_number_point = number << fractional_bits;
}

Fixed::Fixed(const float number){
    std::cout << "Float constructor called" << std::endl;
    fixed_number_point = roundf(number * (1 << fractional_bits));
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_number_point;
}

Fixed &Fixed::operator = (const Fixed &fixed){
    std::cout << "Copy Assignation operator called" << std::endl;
    fixed_number_point = fixed.fixed_number_point;
    return *this;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    fixed_number_point = raw;
}
 
float Fixed::toFloat( void ) const {
    return ((float) this->fixed_number_point / (1 << fractional_bits));
}

int Fixed::toInt( void ) const {
    return fixed_number_point >> fractional_bits;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fix){
    out << fix.toFloat();
    return out;
}