#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal{
    protected:
        std::string type;

    public:
        AAnimal(void);
        virtual ~AAnimal(void);

        AAnimal(const AAnimal &name);
        AAnimal(std::string const type);
        AAnimal &operator=(const AAnimal &name);

        std::string getType(void) const;
        void setType(std::string type);

        virtual void makeSound() const = 0;
};

#endif
