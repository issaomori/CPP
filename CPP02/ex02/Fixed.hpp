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

    bool operator>(const Fixed &left) const;
    bool operator>=(const Fixed &left) const;
    bool operator<(const Fixed &left) const;
    bool operator<=(const Fixed &left) const;
    bool operator==(const Fixed &left) const;
    bool operator!=(const Fixed &left) const;

    Fixed operator++(void);
    Fixed operator++(int);
    Fixed operator--(void);
    Fixed operator--(int);

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;

    static Fixed &min(Fixed &p1, Fixed &p2);
    static Fixed &max(Fixed &p1, Fixed &p2);
    static const Fixed &min(const Fixed &p1, const Fixed &p2);
    static const Fixed &max(const Fixed &p1, const Fixed &p2);
};

std::ostream &operator << (std::ostream &out, Fixed const &f);

#endif