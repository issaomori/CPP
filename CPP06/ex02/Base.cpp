#include "Base.hpp"

Base::~Base(){
}


void identify(Base &ptr){
    try {
        A& a = dynamic_cast< A& >(ptr);
        std::cout << "A" << std::endl;
        (void)a;
    } 
    catch(const std::exception& e) {
        try {
            B& b = dynamic_cast< B& >(ptr);
            std::cout << "B" << std::endl;
            (void)b;
        } 
        catch( const std::exception& e ) {
            try {
                C& c = dynamic_cast< C& >(ptr);
                std::cout << "C" << std::endl;
                (void)c;
            }
            catch( const std::exception& e ) {
                std::cout << "unknown" << std::endl;
            }
        }
    }
}

void identify(Base *ptr) {
Base *a = dynamic_cast<A*>(ptr);
  if (a == NULL)
  {
    a = dynamic_cast<B*>(ptr);
    if (a == NULL)
      std::cout << "C" << std::endl;
    else 
      std::cout << "B" << std::endl;
    return ;
  }
  std::cout << "A" << std::endl;
}

Base *generate(void){
    int randomValue = time(0) % 3;
    switch (randomValue) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            std::cout << "ERROR: Unable to generate an object!" << std::endl;
            return NULL;
    }   
}
