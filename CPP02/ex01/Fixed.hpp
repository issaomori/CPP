#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

    private:
    int fixed_number_point;
    static const int fractional_bits = 8;

    public:
    Fixed();
    ~Fixed();

    Fixed(const Fixed &fixed);
    Fixed(const int number);
    Fixed(const float number);

    Fixed &operator = (const Fixed &fixed);
    int getRawBits( void ) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator << (std::ostream &out, Fixed const &f);

#endif