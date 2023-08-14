#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque <T> >

class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack() : std::stack<T, Container>(){};
        ~MutantStack(){};
        MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy){};
        MutantStack &operator=(const MutantStack &rhs){
            this->c = rhs.c;
            return *this;
        };

        typedef typename std::stack<T, Container>::container_type::iterator iterator;

        iterator begin(){
            return this->c.begin();
        };
        iterator end(){
            return this->c.end();
        };
    typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;

        const_iterator begin() const{
            return this->c.begin();
        };
        const_iterator end() const{
            return this->c.end();
        };
};

#endif
