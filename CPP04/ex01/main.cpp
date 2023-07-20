#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// j->makeSound();
// meta->makeSound();
// // ... CONTINUAR A MAIN<< ...
// return 0;
// }

int main()
{
    const Animal* animal = new Animal();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongCat* wrongCat = new WrongCat();

    std::cout << "Testing Animal:" << std::endl;
    std::cout << "Type: " << animal->getType() << std::endl;
    animal->makeSound();

    std::cout << "\nTesting Cat:" << std::endl;
    std::cout << "Type: " << cat->getType() << std::endl;
    cat->makeSound();

    std::cout << "\nTesting Dog:" << std::endl;
    std::cout << "Type: " << dog->getType() << std::endl;
    dog->makeSound();

    std::cout << "\nTesting WrongAnimal:" << std::endl;
    std::cout << "Type: " << wrongAnimal->getType() << std::endl;
    wrongAnimal->makeSound();

    std::cout << "\nTesting WrongCat:" << std::endl;
    std::cout << "Type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();

    // Clean up
    delete animal;
    delete cat;
    delete dog;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
