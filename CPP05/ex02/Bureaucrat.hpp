#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        ~Bureaucrat();

        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &rhs);

        std::string getName() const;
        int getGrade() const;

        int incrementGrade();
        int decrementGrade();

        void signForm(Form& form) const;

    class GradeTooHighException : public std::exception{
        public:
            virtual const char *what() const throw();
    };
    
    class GradeTooLowException : public std::exception{
        public:
            virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif
