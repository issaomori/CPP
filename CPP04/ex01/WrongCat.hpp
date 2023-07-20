#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
        WrongCat(void);
        ~WrongCat(void);

        WrongCat(const WrongCat &name);
        WrongCat &operator=(const WrongCat &name);

        void makeSound(void) const;
};

#endif