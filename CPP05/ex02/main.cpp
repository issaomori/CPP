#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    Bureaucrat person1("Aime", 50);
    Bureaucrat person2("President", 1);

    AForm *form1 = new PresidentialPardonForm("Pardon_195");
    AForm *form2 = new RobotomyRequestForm("Robotomy_00");
    AForm *form3 = new ShrubberyCreationForm("Shrubbery_01");

    std::cout << std::string(80, '-') << std::endl;
    std::cout << *form1 << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    try {
        std::cout << "Person 50 sign Presidential Pardon Form 25/5" << std::endl;
        person1.signForm(*form1);

        std::cout << "Person 50 execute Presidential Pardon Form 25/5" << std::endl;
        person1.execForm(*form1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Person 50 sign Robotomy Request Form 72/45" << std::endl;
        person1.signForm(*form2);

        std::cout << "Person 50 execute Robotomy Request Form 72/45" << std::endl;
        person1.execForm(*form2);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Person 50 sign Shrubbery Creation Form 145/137" << std::endl;
        person1.signForm(*form3);

        std::cout << "Person 50 execute Shrubbery Creation Form 145/137" << std::endl;
        person1.execForm(*form3);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::string(80, '-') << std::endl;

    try {
        std::cout << "Person 1 sign Presidential Pardon Form 25/5" << std::endl;
        person2.signForm(*form1);

        std::cout << "Person 1 execute Presidential Pardon Form 25/5" << std::endl;
        person2.execForm(*form1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Person 1 sign Robotomy Request Form 72/45" << std::endl;
        person2.signForm(*form2);

        std::cout << "Person 1 execute Robotomy Request Form 72/45" << std::endl;
        person2.execForm(*form2);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << std::string(80, '-') << std::endl;
    std::cout << *form1 << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    delete form1;
    delete form2;
    delete form3;

    return 0;
}
