#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    Dog basic;
    {
        Dog tmp = basic;
    }

    const Animal* animals[6] = { new Dog(), new Dog(), new Cat(), new Cat(), new Dog(), new Cat() };
    for (int i = 0; i < 6; i++) {
        animals[i]->makeSound();
        delete animals[i];
    }

    Cat* cat = new Cat();
    cat->getBrain()->setIdea("Idea 1", 0);
    cat->getBrain()->setIdea("Idea 2", 1);

    Cat* cat2 = new Cat();
    *cat2 = *cat;

    std::cout << "Cat1 Brain Ideas: " << cat->getBrain()->getIdea(0) << ", " << cat->getBrain()->getIdea(1) << std::endl;
    std::cout << "Cat2 Brain Ideas: " << cat2->getBrain()->getIdea(0) << ", " << cat2->getBrain()->getIdea(1) << std::endl;

    delete cat;
    delete cat2;

    return 0;
}
