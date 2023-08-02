#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
    Bureaucrat person1("Aime", 50);
    Bureaucrat *person2 = new Bureaucrat("Teo", 150);

    AForm *form1;
    AForm *form2;
    AForm *form3;
    AForm *fail;

    Intern someone;

    std::cout << std::string(80, '-') << std::endl;

    // Creating and executing forms
    try {
        std::cout << "Intern creates presidential request to President..." << std::endl;
        form1 = someone.makeForm("presidential request", "President");
        person1.signForm(*form1);
        person1.execForm(*form1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "Intern creates robotomy request to Jonh..." << std::endl;
        form2 = someone.makeForm("robotomy request", "Jonh");
        person1.signForm(*form2);
        person1.execForm(*form2);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "Intern creates shrubbery request to Aime..." << std::endl;
        form3 = someone.makeForm("shrubbery request", "Aime");
        person1.signForm(*form3);
        person1.execForm(*form3);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::string(80, '-') << std::endl;

    // Creating and executing invalid form
    try {
        std::cout << "Someone intern creating invalid form" << std::endl;
        fail = someone.makeForm("invalid form", "Nobody");
        person2->signForm(*fail);
        std::cout << *fail;
        person2->execForm(*fail);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::string(80, '-') << std::endl;

    // Displaying forms
    if (form1) {
        std::cout << *form1 << std::endl;
        delete form1;
    }
    if (form2) {
        std::cout << *form2 << std::endl;
        delete form2;
    }
    if (form3) {
        std::cout << *form3 << std::endl;
        delete form3;
    }

    delete person2;

    return 0;
}