#ifndef CAT_HPP
#define CAT_HPP

// #include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
    private:
        Brain *brain;
    public:
        Cat(void);
        ~Cat(void);
        
        Cat(Cat const &name);
        Cat &operator=(Cat const &name);

        void makeSound(void) const;

        Brain *getBrain() const;
};

#endif
