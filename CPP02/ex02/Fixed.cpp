#include "Fixed.hpp"

Fixed::Fixed( void ){
    fixed_number_point = 0;
}

Fixed::~Fixed( void ){
}

Fixed::Fixed(const Fixed &fixed){
    *this = fixed;
}

Fixed::Fixed(const int number){
    fixed_number_point = number << fractional_bits;
}

Fixed::Fixed(const float number){
    fixed_number_point = roundf(number * (1 << fractional_bits));
}

int Fixed::getRawBits( void ) const{
    return fixed_number_point;
}

Fixed &Fixed::operator = (const Fixed &fixed){
    fixed_number_point = fixed.fixed_number_point;
    return *this;
}

void Fixed::setRawBits(int const raw){
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

bool Fixed::operator>(const Fixed &left) const{
    return this->toFloat() > left.toFloat();
}

bool Fixed::operator>=(const Fixed &left) const{
    return this->toFloat() >= left.toFloat();
}

bool Fixed::operator<(const Fixed &left) const{
    return this->toFloat() < left.toFloat();
}

bool Fixed::operator<=(const Fixed &left) const{
    return this->toFloat() <= left.toFloat();
}

bool Fixed::operator==(const Fixed &left) const{
    return this->toFloat() == left.toFloat();
}

bool Fixed::operator!=(const Fixed &left) const{
    return this->toFloat() != left.toFloat();
}

Fixed Fixed::operator++(void){
    ++this->fixed_number_point;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed aux(*this);
    this->fixed_number_point++;
    return aux;
}

Fixed Fixed::operator--(void){
    --this->fixed_number_point;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed aux(*this);
    this->fixed_number_point--;
    return aux;
}

Fixed Fixed::operator+(const Fixed &other) const{
    Fixed tmp = (this->toFloat() + other.toFloat());
    return tmp;
}

Fixed Fixed::operator-(const Fixed &other) const{
    Fixed tmp = (this->toFloat() - other.toFloat());
    return tmp;
}

Fixed Fixed::operator*(const Fixed &other) const{
    Fixed tmp = (this->toFloat() * other.toFloat());
    return tmp;
}

Fixed Fixed::operator/(const Fixed &other) const{
    Fixed tmp = (this->toFloat() / other.toFloat());
    return tmp;
}

Fixed &min(Fixed &p1,Fixed &p2){
    if (p1 < p2)
        return p1;
    else
        return p2;
}

Fixed &max(Fixed &p1,Fixed &p2){
    if (p1 > p2)
        return p1;
    else
        return p2;
}

const Fixed &Fixed::min(const Fixed &p1,const Fixed &p2){
    if (p1 < p2)
        return p1;
    else
        return p2;
}

const Fixed &Fixed::max(const Fixed &p1,const Fixed &p2){
    if (p1 > p2)
        return p1;
    else
        return p2;
}
