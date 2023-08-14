#include "Converter.hpp"

std::string Converter::_input = "\0";
 char Converter::_c = 0;
 int Converter::_i = 0;
 float Converter::_f = 0;
 double Converter::_d = 0;
 bool Converter::_nothing = 0;

Converter::Converter(void){
    this->_c = 0;
    this->_i = 0;
    this->_f = 0;
    this->_d = 0;
}

Converter::~Converter(void){
}

Converter::Converter(const Converter &copy){
    *this = copy;
}

Converter &Converter::operator=(const Converter &rhs){
    this->_input = rhs._input;
    this->_c = rhs._c;
    this->_i = rhs._i;
    this->_f = rhs._f;
    this->_d = rhs._d;
    this->_nothing = rhs._nothing;

    return *this;
}

char Converter::checkInputType(void){

char *check = new char;
char result;

*check = this->_input[0];
if (*check == 'c') {
    this->_c = this->_input[0];
    this->converter(_c);
    result = _c;
} else if (*check == 'i') {
    this->_i = static_cast<int>(strtol(this->_input.c_str(), NULL, 10));
    this->converter(_i);
    result = _i;
} else if (*check == 'f') {
    this->_f = strtof(this->_input.c_str(), NULL);
    this->converter(_f);
    result = _f;
} else if (*check == 'd') {
    this->_d = strtod(this->_input.c_str(), NULL);
    this->converter(_d);
    result = _d;
} else {
    this->converterNothing();
    result = 0; // You might need to adjust this based on your logic
}
return result;
}

void Converter::converter(const char c){
	_i = static_cast<int>(c);
	_d = static_cast<double>(c);
	_f = static_cast<float>(c);
}

void Converter::converter(const int i) {
	_c = static_cast<char>(i);
	_f = static_cast<float>(i);
	_d = static_cast<double>(i);
}

void Converter::converter(const float f) {
	_c = static_cast<char>(f);
	_i = static_cast<int>(f);
	_d = static_cast<double>(f);
}

void Converter::converter(const double d){
	_c = static_cast<char>(d);
	_i = static_cast<int>(d);
	_f = static_cast<float>(d);
	
}

void Converter::converterNothing(void) {
	char *check;

	_c = 0;
	_i = 0;
	_f = strtof(_input.c_str(), &check);
	_d = strtod(_input.c_str(), &check);
	if (*check != '\0') {
        _nothing = true;
	}
}

Converter::Converter(const std::string input){
    _input = input;
    char check = _input[0];
    if (check == 'c') {
    this->converter(_c);
} else if (check == 'i') {
    this->converter(_i);
} else if (check == 'f') {
    this->converter(_f);
} else if (check == 'd') {
    this->converter(_d);
} else {
    this->converterNothing();
    return;
}
}


void Converter::convertPrint(void) {
    if (_nothing) {
        std::cout << "char: Cannot Convert" << std::endl;
        std::cout << "int: Cannot Convert" << std::endl;
        std::cout << "float: Cannot Convert" << std::endl;
        std::cout << "double: Cannot Convert" << std::endl;
    } else {
        if (_i > 32 && _i < 127) {
            std::cout << "char: " << _c << std::endl;
        } else if (std::isinf(_d) || std::isnan(_d)) {
            std::cout << "char: Cannot display" << std::endl;
        } else {
            std::cout << "char: non displayable" << std::endl;
        }

        if (_d < -2147483648 || _d > 2147483647 ||
            std::isinf(_d) || std::isnan(_d)) {
            std::cout << "int: Cannot Convert" << std::endl;
        } else {
            std::cout << "int: " << _i << std::endl;
        }

        float f = _f;
        if (f - _i != 0) {
            std::cout << "float: " << _f << "f" << std::endl;
        } else {
            std::cout << "float: " << _f << ".0f" << std::endl;
        }

        double d = _d;
        if (d - _i != 0) {
            std::cout << "double: " << _d << std::endl;
        } else {
            std::cout << "double: " << _d << ".0" << std::endl;
        }
    }
}

const char *Converter::NotConverter::what() const throw() { 
    return ("Invalid formart.\n"); 
}
