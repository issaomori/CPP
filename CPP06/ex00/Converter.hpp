#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <cmath>


class Converter{
    private:
        static std::string _input;
        static char _c;
        static int _i;
        static float _f;
        static double _d;
        static bool _nothing;

        Converter(void);
        Converter(const Converter &copy);
        Converter &operator=(const Converter &rhs);

    public:
        Converter(const std::string input);
        ~Converter(void);
        char checkInputType(void);

        static void converter(const char c);
        static void converter(const int i);
        static void converter(const float f);
        static void converter(const double d);
        static void converterNothing(void);

        void errorPrint(std::string const &type, std::string str);
        void convertPrint(void);

        class NotConverter : public std::exception
	{
        public:
            virtual const char *what() const throw();
	};
};

#endif
