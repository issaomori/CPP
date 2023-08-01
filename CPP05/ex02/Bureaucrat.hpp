#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "AForm.hpp"

class AForm;

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

        void signForm(AForm &aform) const;
        void execForm(AForm const &aform);

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
