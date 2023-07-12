#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

    private:
    int fixed_number_point;
    static const int fractional_bits;

    public:
    Fixed();
    ~Fixed();

    Fixed(const Fixed &fixed);
    Fixed &operator = (const Fixed &fixed);
    int getRawBits( void ) const;
    void setRawBits(int const raw);
    float toFloat( void );
    int toInt( void );
};

std::ostream &operator << (std::ostream &out, Fixed const &f);

#endif