#ifndef CAT_HPP
#define CAT_HPP

// #include <iostream>
#include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat(void);
        ~Cat(void);
        
        Cat(Cat const &name);
        Cat &operator=(Cat const &name);

        void makeSound(void) const;
};

#endif
