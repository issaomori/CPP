#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150){
    return;
}

AForm::~AForm(){
    return;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
    if (this->gradeToSign() < 1 || this->gradeToExec() < 1 || 
    this->gradeToSign() > 150 || this->gradeToExec() > 150){
        if (this->gradeToSign() < 1 || this->gradeToExec() < 1) {
            throw GradeTooHighException();
        } else 
            throw GradeTooLowException();
}
}

AForm::AForm(const AForm &rhs) : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150){
    *this = rhs;
    if (this->gradeToSign() < 1 || this->gradeToExec() < 1) {
    	throw GradeTooHighException();
	}
	if (this->gradeToSign() > 150 || this->gradeToExec() > 150) {
		throw GradeTooLowException();
	}
    return;
}

AForm &AForm::operator=(const AForm &rhs){
    if (this == &rhs) {
        return *this; // Verificar se não é a mesma instância
    }

    std::cout << "Copy assignment operator called" << std::endl;

    const_cast<std::string&>(_name)= rhs.getName();
    _isSigned = rhs.isSigned();
    const_cast<int&>(_gradeToSign) = rhs.gradeToSign();
    const_cast<int&>(_gradeToExec) = rhs.gradeToExec();
    setTarget(rhs.getTarget());

    return *this;
}

void AForm::setTarget(std::string target){
    const_cast<std::string&>(this->_target) = target;
}

std::string AForm::getName() const{
    return this->_name;
}

bool AForm::isSigned() const{
    return this->_isSigned;
}

int AForm::gradeToSign() const{
    return this->_gradeToSign;
}

int AForm::gradeToExec() const{
    return this->_gradeToExec;
}

const std::string AForm::getTarget(void) const{
    return this->_target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() <= this->gradeToSign())
        this->_isSigned = true;
    throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high.";
} 

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

const char *AForm::UnsignedFormException::what() const throw() {
	return "The form is unsigned.";
}

std::ostream & operator<<(std::ostream & out, AForm const &rhs){
    out << "AForm Info: " << rhs.getName() << std::endl;
    out << (rhs.isSigned() ? "yes" : "no") << std::endl;
    out << "Grade Signed: " << rhs.gradeToSign() << std::endl;
    out << "Grade Execute: " << rhs.gradeToExec() << std::endl;

    return out;
}
