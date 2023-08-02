#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{

    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm (const std::string target);

        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

        void exec(Bureaucrat const &executor) const;

};

#endif
