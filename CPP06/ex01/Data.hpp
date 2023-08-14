#ifndef DATA_HPP
#define DATA_HPP

#include <stdint.h>
#include <ostream>
#include <string>

class Data
{
public:

	Data(std::string str_data);
	~Data(void);

	static std::string	getData(void);

private:
	static std::string	_data;

	Data(void);

	Data(const Data &copy);
	Data & operator=(const Data &rhs);
	
};

#endif
