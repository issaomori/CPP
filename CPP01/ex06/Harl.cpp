#include "Harl.hpp"

Harl::Harl(){
    level_functions ["DEBUG"] = &Harl::debug;
    level_functions ["INFO"] = &Harl::info;
    level_functions ["WARNING"] = &Harl::warning;
    level_functions ["ERROR"] = &Harl::error;
    }

Harl::~Harl(){
}

void Harl::complain(std::string level){
    std::map<std::string, LevelFunction>::iterator it = level_functions.find(level);
    if (it != level_functions.end())
        (this->*(it->second))();
}

void Harl::debug( void ){
    std::cout << "DEBUG: " << std::endl;
    std::cout << " I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
    std::cout << "INFO: " << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;
}

void Harl::warning( void ){
    std::cout << "WARNING: " << std::endl;
    std::cout << " I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month.." << std::endl;
}

void Harl::error( void ){
    std::cout << "ERROR: " << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
