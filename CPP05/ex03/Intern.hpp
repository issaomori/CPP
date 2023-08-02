#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &copy);

        Intern&operator=(const Intern &rhs);

        AForm* makeForm(const std::string name, const std::string target);
		AForm* createPresidentialForm(const std::string target) const;
		AForm* createRobotomyForm(const std::string target) const;
		AForm* createShrubberyForm(const std::string target) const;

        class InvalidFormException : public std::exception{
            public:
                const char *what() const throw();
        };
};
#endif
