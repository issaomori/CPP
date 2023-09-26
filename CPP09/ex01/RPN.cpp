#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return (*this);
}

double RPN::RPNcalculate(std::string arg) {
    if (!IsValidExpression(arg))
        throw "Error: Invalid expression";

    std::stack<double> rpn;
    std::istringstream iss(arg);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && IsOperator(token[0])) {
            if (rpn.size() < 2)
                throw "Error";
            PerformOperation(rpn, token[0]);
        } else {
            double number = strtod(token.c_str(), NULL);
            rpn.push(number);
        }
    }

    if (rpn.size() != 1)
        throw "Error: RPN error execution";
    else
        return rpn.top();
}

bool RPN::IsOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::IsValidExpression(std::string arg) {
    std::stack<char> operators;
    std::istringstream iss(arg);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && IsOperator(token[0])) {
            if (operators.size() < 2)
                return false; // Não há operandos suficientes para o operador
            operators.push(token[0]);
        } else {
            double number;
            if (std::istringstream(token) >> number) {
                // É um número, não faz nada
            } else {
                // Não é um operador nem um número válido
                return false;
            }
        }
    }

    // Deve haver um operador a menos do que o número de operandos
    return (operators.size() == 1);
}

void RPN::PerformOperation(std::stack<double>& rpn, char op) {
    double number2 = rpn.top();
    rpn.pop();
    double number1 = rpn.top();
    rpn.pop();
    double result;

    switch (op) {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            if (number2 == 0)
                throw "Error: Division by zero";
            result = number1 / number2;
            break;
        default:
            throw "Error: Invalid operator";
    }

    rpn.push(result);
}
