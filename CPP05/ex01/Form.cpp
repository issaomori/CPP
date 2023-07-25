#include "Form.hpp"
#include "Bureaucrat.hpp"

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
    if (this != &rhs)
        _isSigned = rhs.gradeToSign();
    return *this;
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

void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= this->gradeToSign())
        this->_isSigned = true;
    throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high.";
} 

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

std::ostream &operator<<(std::ostream &out, const Form &rhs){
    out << "Form Info: " << rhs.getName() << std::endl;
    out << (rhs.isSigned() ? "yes" : "no") << std::endl;
    out << "Grade Signed: " << rhs.gradeToSign() << std::endl;
    out << "Grade Execute: " << rhs.gradeToExec() << std::endl;

    return out;
}
