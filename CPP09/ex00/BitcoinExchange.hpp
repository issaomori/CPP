#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange{
    private:
        std::string _name;
        double _rate;
    public:
        BitcoinExchange();
        ~BitcoinExchange();

        BitcoinExchange(std::string name, double rate);
        BitcoinExchange(BitcoinExchange const &copy);

        BitcoinExchange &operator=(BitcoinExchange const &rhs);

        std::string getName() const;
        double getRate() const;
        void setName(std::string name);
        void setRate(double rate);
        void printOutput(std::string input, double amount);
};
#endif
