#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>  
#include <string>
#include <climits>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, double> db;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        void LoadData();
        void PrintData();
        void InputHandler(std::string filename);
        int CountWords(std::string line);
        int ParseInput(int year, int month, int day, double value, std::string line);
        void PrintExchangeInfo(std::string input, double value);
};

#endif
