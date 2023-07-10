#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();

        Zombie(std::string name);
        void announce();
        Zombie* newZombie( std::string name );
        void randomChump( std::string name );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif