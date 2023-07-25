#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150){
}

Form::~Form(){
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
    if (this->gradeToSign() < 1 || this->gradeToExec() < 1)
        throw GradeTooHighException();
    if (this->gradeToSign() > 150 || this->gradeToExec() > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &rhs) : _name(rhs.getName()), _gradeToSign(rhs.gradeToSign()), _gradeToExec(rhs.gradeToExec()){
}

Form &Form::operator=(const Form &rhs){

}

std::string Form::getName() const{
    return this->_name;
}

bool Form::isSigned() const{
    return this->_isSigned;
}

int Form::gradeToSign() const{
    return this->_gradeToSign;
}

int Form::gradeToExec() const{
    return this->_gradeToExec;
}

void Form::beSigned(const Bureaucrat &bureaucrat){

}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high.";
} 

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

std::ostream &operator<<(std::ostream &out, const Form &rhs){

}