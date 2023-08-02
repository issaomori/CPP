#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm{

    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm (const std::string target);

        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

        void exec(Bureaucrat const &executor) const;
};

#endif
