
#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <stdlib.h>

class RPN
{

public:
    RPN();
    ~RPN();

    RPN(const RPN &copy);
    RPN &operator=(const RPN &rhs);

    double RPNcalculate(std::string arg);

    bool IsOperator(char c);
    bool IsValidExpression(std::string arg);
    void PerformOperation(std::stack<double>& rpn, char op);
};

#endif
