#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExec;
        
    protected:
        const std::string _target;

    public:
        AForm();
        virtual ~AForm();
    
        AForm(const std::string name, int gradeToSign, int gradeToExec);
        AForm(const AForm &rhs);

        AForm &operator=(const AForm &rhs);

        void setTarget(std::string target);
        std::string getName() const;
        bool isSigned() const;
        int gradeToSign() const;
        int gradeToExec() const;
        const std::string getTarget(void) const;

        void beSigned(const Bureaucrat &bureaucrat);

        virtual void exec(Bureaucrat const &executor) const = 0;
        class GradeTooHighException : public std::exception{
        public:
            virtual const char *what() const throw();
        };
    
        class GradeTooLowException : public std::exception{
        public:
            virtual const char *what() const throw();
        };
        class UnsignedFormException: public std::exception{
            public:
                const char* what() const throw();
        };
};

std::ostream & operator<<(std::ostream & out, AForm const &rhs);

#endif
