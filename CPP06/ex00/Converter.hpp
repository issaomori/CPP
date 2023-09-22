// #ifndef CONVERTER_HPP
// #define CONVERTER_HPP

// #include <iostream>
// #include <string>
// #include <sstream>
// #include <limits>
// #include <cctype>
// #include <cstdlib>

// float: A representação padrão para um float é geralmente exibida com 6-9 casas decimais de precisão. No entanto, você pode controlar quantas casas decimais deseja exibir usando as formatações de saída, como exemplificado anteriormente.

// double: A representação padrão para um double geralmente exibe 15-17 casas decimais de precisão. Novamente, você pode controlar o número de casas decimais a serem exibidas usando formatações de saída.

// Portanto, sua abordagem original estava alinhada com as convenções padrão. Um int geralmente não tem casas decimais, um float pode ter um número variável de casas decimais, e um double geralmente tem mais casas decimais de precisão em comparação com um float.

#ifndef Converter_HPP
# define Converter_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <string>
# include <cmath>
# include <climits>


#define MIN_INT (-2147483647)
#define MAX_INT 2147483647
#define MIN_FLOAT (-3.402823466e+38F)
#define MAX_FLOAT 3.402823466e+38F
#define MIN_DOUBLE (-1.7976931348623157e+308)
#define MAX_DOUBLE 1.7976931348623157e+308

class Converter {
    
public:

    Converter(const std::string input_convert);
    ~Converter(void);
    char checkInputType(void);

	static void convert(const char value);
	static void convert(const int value);
	static void convert(const float value);
	static void convert(const double value);
    static void convertNothing(void);

	void printError(std::string const& type, std::string msg);
	void printConversion(void);

	class NotConvertible : public std::exception
	{
        public:
            virtual const char *what() const throw();
	};
    
private:

    Converter(void);
    Converter(const Converter &sc);
    Converter &operator=(const Converter &sc);

    static std::string input;
    static char _char;
    static int _int;
    static float _float;
    static double _double;
    static bool nothing;
};

#endif