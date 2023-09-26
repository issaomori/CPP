#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN calculator;
	if (argc != 2)
	{
		std::cout  << "ERROR: wrong arguments for calculation. Try '2 2 +'" << std::endl;
		return (1);
	}
	try
	{
		double result;
		std::string calc = argv[1];
		result = calculator.RPNcalculate(calc);
        std::cout << std::string(80, '-') << std::endl;
		std::cout << "Result = " << result << std::endl;
        std::cout << std::string(80, '-') << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << e << std::endl;
		return (1);
	}
	return (0);
}

// ./RPN "2 2 +"
// 4

// ./RPN "2 2 + 5 *"
// 20

// ./RPN "2 2 + 5 * 2 / 1000 *"
// 10.000