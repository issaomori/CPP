#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", 145, 137){
    this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy){
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs){
    (void)rhs;
    return *this;
}

void ShrubberyCreationForm::exec(Bureaucrat const &executor) const{
    if (!isSigned()) {
		throw AForm::UnsignedFormException();
	}
	else if (executor.getGrade() > this->gradeToExec()) {
		throw AForm::GradeTooLowException();
	}
	else {
		std::ofstream outfile (this->getTarget().c_str());   
        std::string tree =
"                     v .   ._, |_  . \n"
"          `-._  .  /    |/_ \n"
"              \\  _, y | / \n"
"        _.___\\, \\/ -.|| \n"
"          `7-,--.`._||  / / , \n"
"          /'     `-. `./ / |/_.' \n"
"                    |    |// \n"
"                     |_    / \n"
"                     |-   | \n"
"                     |   =| \n"
"                     |    | \n"
"--------------------/ ,  .|--------._ \n";
outfile << tree;
outfile.close();
}
}