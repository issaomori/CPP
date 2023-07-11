#include "Harl.hpp"

int main ( void ){

    std::string input;
    Harl harl;
    while(1){
        std::cout << "Enter a level (or exit to quit): ";
        std::cin >> input;
        if (input == "EXIT")
            return 1;
        if (input != "DEBUG" || input != "INFO" || input != "WARNING" || input != "ERROR")
            std::cout << "Error. Level is not exist. Try again, choose between (DEBUG, INFO, WARNING, ERROR or EXIT)." << std::endl;

        harl.complain(input);
    }
    return 0;
}