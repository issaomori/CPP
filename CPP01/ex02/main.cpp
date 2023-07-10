#include <string>
#include <iostream>


int main (){
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // stringREF = "gabriel";
    //ao mudar o valor da stringREF, o valor da string str também é alterado. Por que?
    //porque stringREF é uma referência para str, ou seja, stringREF é um apelido para str.
    std::cout << "str: " << &str << std::endl;
    std::cout << "stringPTR: " << stringPTR << std::endl;
    std::cout << "stringREF: " << &stringREF << std::endl;

    std::cout << "--------------------------------" << std::endl;

    std::cout << "str: " << str << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;

    return 0;
}
