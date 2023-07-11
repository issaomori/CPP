#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <map>

class Harl{
    private:

    typedef void (Harl::*LevelFunction)(void);
    std::map<std::string, LevelFunction> level_functions;

    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

    public:
    Harl();
    ~Harl();
    void complain( std::string level );
};

#endif