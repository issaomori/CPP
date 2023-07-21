#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
    private:
        Brain *brain;
    public:
        Dog(void);
        ~Dog(void);

        Dog(Dog const &name);
        Dog &operator=(Dog const &name);

        void makeSound(void) const;
        Brain *getBrain() const;
};
#endif