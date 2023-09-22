#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <iostream>

class BitCoinExchange {

    private:
        std::string dataFileName;
        std::map<std::string, float> csvData;

        float convertToFloat(const std::string& value);
        std::pair<std::string, float> makePair(const std::string& pair);
        bool isValidYear(int year);
        bool isValidMonth(int month);
        bool isValidDay(int day);
        bool isValidDateFormat(const std::string& date);
        bool isValidValue(float value);
        void printValue(const std::map<std::string, float>& dataMap, const std::string& inputStr);

    public:
        BitCoinExchange();
        ~BitCoinExchange();
        bool readCSVData(std::map<std::string, float>& dataMap);
        int openFile(std::ifstream& file, const std::string& fileName);
        BitCoinExchange(const std::string& dataFile);
        bool parseData();
        void calculate(const std::map<std::string, float>& csv, const std::string& file);
        std::string trim(const std::string& str);
};

#endif 
