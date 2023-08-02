#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45){
    this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy){
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs){
    (void)rhs;
    return *this;
}

void RobotomyRequestForm::exec(Bureaucrat const &executor) const{
if (!isSigned()) {
        throw UnsignedFormException();
    } else if (executor.getGrade() > gradeToExec()) {
        throw GradeTooLowException();
    } else {
        int nbr = rand();
        if (nbr % 2 != 0) {
            std::cout << "That " << getTarget() << " has been robotomized!" << std::endl; 
        } else {
            std::cout << "Robotomization has failed!" << std::endl; 	
        }
    }
}
