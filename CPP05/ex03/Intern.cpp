#include "Intern.hpp"

Intern::Intern(){
}

Intern::~Intern(){
}

Intern::Intern(const Intern &copy){
    *this = copy;
}

Intern &Intern::operator=(const Intern &rhs){
    (void)rhs;
    return *this;
}

AForm *Intern::makeForm(const std::string name, const std::string target){
    const std::string typesForms[3] = {
        "presidential request",
        "robotomy request",
        "shrubbery request"
    };
    
    AForm* (Intern::*forms[3])(const std::string) const = {
        &Intern::createPresidentialForm,
        &Intern::createRobotomyForm,
        &Intern::createShrubberyForm
    };
    
    for (int i = 0; i < 3; i++) {
        if (typesForms[i].compare(name) == 0) {
            std::cout << "Intern creates " << typesForms[i] << std::endl;
            return ((this->*forms[i])(target));
        }
    }
    
    throw InvalidFormException();
    return NULL;
}

AForm *Intern::createPresidentialForm(const std::string target) const{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyForm(const std::string target) const{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyForm(const std::string target) const{
    return new PresidentialPardonForm(target);
}

const char *Intern::InvalidFormException::what(void) const throw() {
  return ("Non-existent form!!!");
}
