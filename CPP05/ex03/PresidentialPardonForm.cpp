#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", 25, 5){
    this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy){
    *this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs){
    (void)rhs;
    return *this;
}

void PresidentialPardonForm::exec(Bureaucrat const &executor) const{
    if (!isSigned()) {
        throw UnsignedFormException();
    } else if (executor.getGrade() > gradeToExec()) {
        throw GradeTooLowException();
    } else
        std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
