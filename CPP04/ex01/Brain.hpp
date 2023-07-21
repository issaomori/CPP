#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    
    public:
        Brain(void);
        ~Brain(void);
    
        Brain(Brain const &name);
        Brain &operator=(Brain const &name);

        void setIdea(std::string idea, int i);
        std::string getIdea(int i) const;
};

#endif
