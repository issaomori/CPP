#include "Zombie.hpp"

int main( void ){
    std::string zombie_name;
    
    std::cout << "Enter a name for your zombie(stack): ";
    std::cin >> zombie_name;
    Zombie zombie_stack(zombie_name);

    std::cout << "Enter a name for your zombie(heap): ";
    std::cin >> zombie_name;

    Zombie* zombie_heap = newZombie(zombie_name);
    zombie_heap->announce();
    delete zombie_heap;

    std::cout << "Create ramdom name of Zoombie(ramdom): ";
    randomChump("Ronaldo");

    return 0;
}
