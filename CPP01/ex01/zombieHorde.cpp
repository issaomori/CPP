#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){

    if (N <= 0){
        std::cout << "Error: Insert a number more than 0." << std::endl;
        return NULL;

    }

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++){
        horde[i].setZombieName(name);
    }
    return horde;
}
