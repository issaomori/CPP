#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExec;
    public:
        Form();
        ~Form();

        Form(const std::string name, const int gradeToSign, const int gradeToExec);
        Form(const Form &rhs);

        Form &operator=(const Form &rhs);

        std::string getName() const;
        bool isSigned() const;
        int gradeToSign() const;
        int gradeToExec() const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception{
        public:
            virtual const char *what() const throw();
        };
    
        class GradeTooLowException : public std::exception{
        public:
            virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif
