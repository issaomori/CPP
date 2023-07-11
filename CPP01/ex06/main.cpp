#include "Harl.hpp"

int main (int argc, char **argv){

    if (argc != 2){
        std::cout << "Error. Invalid number of arguments." << std::endl;
        return 1;
    }

    std::string input = argv[1];
    Harl harl;

        if (input == "DEBUG" || input == "INFO" || input == "WARNING" || input == "ERROR")
            harl.complain(input);
        else
            std::cout << "Error. Level is not exist. Try again, choose between (DEBUG, INFO, WARNING, ERROR or EXIT)." << std::endl;
    return 0;
}