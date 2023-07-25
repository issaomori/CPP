#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"){
    this->grade = 150;
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name){
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade = grade;
    //assim perco menos tempo.
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy){
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs){
    if (this != &rhs)
        this->grade = rhs.getGrade();
    return *this;
}

std::string Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

int Bureaucrat::incrementGrade(){
    if (this->getGrade() - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
    return this->grade;
}

int Bureaucrat::decrementGrade(){
    if (this->getGrade()  + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
    return this->grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade too low.";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs){
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return out;
}
