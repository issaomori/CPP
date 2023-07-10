#include "Zombie.hpp"

int main ( void ){
    
    Zombie *horde;

    std::string N;
    std::string zombie_name;

    std::cout << "Insert a number: " << std::endl;
    std::getline(std::cin >> std::ws, N);
    if (!N.find_first_not_of("0123456789")){
        std::cout << "Error: Insert a number." << std::endl;
        return 0;
    }

    std::cout << "Insert a name: " << std::endl;
    std::cin >> zombie_name;

    std::istringstream iss(N);
    int n;
    iss >> n;

    horde = zombieHorde(n, zombie_name);

    for (int i = 0; i < n; i++){
        horde[i].announce();
    }
    delete [] horde;

    return 0;
}
