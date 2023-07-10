#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{

    private:
        std::string type;
    public:
        Weapon();
        ~Weapon();

        Weapon(std::string str);
        const std::string &getType();
        void setType(std::string newStr);
};

#endif