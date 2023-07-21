#ifndef CAT_HPP
#define CAT_HPP

// #include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private:
        Brain *brain;
    public:
        Cat(void);
        ~Cat(void);
        
        Cat(Cat const &name);
        Cat &operator=(Cat const &name);

        void makeSound(void) const;

        Brain* getBrain() const { return brain; }
};

#endif
