#include "Converter.hpp"

std::string Converter::input = "\0";
char Converter::_char = 0;
int Converter::_int = 0;
float Converter::_float = 0;
double Converter::_double = 0;
bool Converter::nothing = 0;


Converter::Converter() {
    this->_char = 0;
    this->_int = 0;
    this->_double = 0;
    this->_float = 0;
}

Converter::~Converter() {
}

Converter::Converter(const Converter &sc) {
    *this = sc;
}

Converter& Converter::operator=(const Converter &sc) {
    this->input = sc.input;
    this->_char = sc._char;
    this->_double = sc._double;
    this->_float = sc._float;
    this->_int = sc._int;
    this->nothing = sc.nothing;
    return *this;
}

Converter::Converter(const std::string input_convert) {
    input = input_convert;
    nothing = false;
    char check;

    check = this->checkInputType();
    if (check == 'c') {
        this->convert(_char);
    }
    if (check == 'i') {
        this->convert(_int);
    }
    if (check == 'f') {
        this->convert(_float);
    }
    if (check == 'd') {
        this->convert(_double);
    }
    if (check == 0) {
        this->convertNothing();
        return ;
    }
}

char Converter::checkInputType() {
    char *check;

    if (this->input.length() == 1 && std::isalpha(this->input[0])) {
        this->_char = this->input[0];
        return 'c';
    }
    strtol(this->input.c_str(), &check, 10);
    if (*check == '\0') { 
        this->_int = static_cast<int>(strtol(this->input.c_str(), NULL, 10));
        return 'i';
    }
    strtod(this->input.c_str(), &check);
    if (*check == '\0') {
        this->_double = strtod(this->input.c_str(), &check);
        return 'd';
    }
    strtof(this->input.c_str(), &check);
    if (*check == 'f' && *(check + 1) == '\0') {
        this->_float = strtof(this->input.c_str(), &check);
        return 'f';
    }
    return 0;
}

void Converter::convert(const char value){
    _int = static_cast<int>(value);
    _double = static_cast<double>(value);
    _float = static_cast<float>(value);
}

void Converter::convert(const int value) {
    _char = static_cast<char>(value);
    _float = static_cast<float>(value);
    _double = static_cast<double>(value);
}

void Converter::convert(const float value) {
    _char = static_cast<char>(value);
    _int = static_cast<int>(value);
    _double = static_cast<double>(value);
}

void Converter::convert(const double value){
    _char = static_cast<char>(value);
    _int = static_cast<int>(value);
    _float = static_cast<float>(value);
}

void Converter::convertNothing(void) {
    char *check;

    _char = 0;
    _int = 0;
    _float = strtof(input.c_str(), &check);
    _double = strtod(input.c_str(), &check);
    if (*check != '\0') {
        nothing = true;
    }
}

void Converter::printConversion(void) {
    if (nothing) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    } else {
        if (_int >= 32 && _int <= 126)
            std::cout << "char: '" << _char << "'" << std::endl;
        else if ((std::isinf(_double) || std::isnan(_double)))
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;

        if (_int >= MIN_INT && _int <= MAX_INT)
            std::cout << "int: " << _int << std::endl;
        else
            std::cout << "int: impossible" << std::endl;

        if (_float >= MIN_FLOAT && _float <= MAX_FLOAT)
            std::cout << "float: " << _float << "f" << std::endl;
        else
            std::cout << "float: impossible" << std::endl;

        if (_double >= MIN_DOUBLE && _double <= MAX_DOUBLE)
            std::cout << "double: " << _double << std::endl;
        else
            std::cout << "double: impossible" << std::endl;
    }
}


const char* Converter::NotConvertible::what() const throw() {
    return ("Invalid format or can't be converted.");
}
