#include "Data.hpp"

std::string	Data::_data = "\0";

Data::Data(void){
}

Data::~Data(void){
}

Data::Data(std::string str_data){
    _data = str_data;
}

std::string Data::getData(void){
    return _data;
}

Data::Data(const Data &copy){
    this->_data = copy.getData();
}

Data &Data::operator=(const Data &rhs){
    this->_data = rhs._data;
    return *this;
}

std::ostream & operator<<(std::ostream& out, const Data& data)
{
	out << "Data( " << "str_data= " << data.getData() << ")"<< std::endl;
	return out;
}
