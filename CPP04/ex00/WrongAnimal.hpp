#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
    protected:
        std::string type;
    
    public:
        WrongAnimal(void);
        ~WrongAnimal(void);

        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &name);
        WrongAnimal &operator=(const WrongAnimal &name);

        std::string getType(void) const;
        void setType(std::string type);
        
        void makeSound(void) const;

};
#endif