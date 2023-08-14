#include "Base.hpp"
#include <cstdlib>

class D: public Base{
};

int main (void) {
	Base *random = generate();
	A *a = new A();
	B *b = new B();
	C *c = new C();
	D *d = new D();
	A *e = NULL;

    std::cout << std::string(30, '-') << std::endl;
    
	std::cout << "Type A test:" << std::endl;
	identify(a);
	identify(*a);
    std::cout << std::endl;

	std::cout << "Type B test:" << std::endl;
	identify(b);
	identify(*b);
    std::cout << std::endl;

	std::cout << "Type C test:" << std::endl;
	identify(c);
	identify(*c);
    std::cout << std::endl;

	std::cout << "Random type test:" << std::endl;
	identify(random);
	identify(*random);
    std::cout << std::endl;

	std::cout << "Unknow type test:" << std::endl;
	identify(e);
	identify(*d);
    std::cout << std::string(30, '-') << std::endl;

	delete (a);
	delete (b);
	delete (c);
	delete (random);
	delete (d);

  	return (0);
}
