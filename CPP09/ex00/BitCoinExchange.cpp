#include "BitCoinExchange.hpp"

BitCoinExchange::BitCoinExchange() : dataFileName("data.csv") {}

BitCoinExchange::~BitCoinExchange() {}

BitCoinExchange::BitCoinExchange(const std::string& dataFile) : dataFileName(dataFile) {}

bool BitCoinExchange::parseData() {
    return readCSVData(csvData);
}
#include <cstdlib> // Para strtod

// ...

bool BitCoinExchange::readCSVData(std::map<std::string, float>& dataMap) {
    std::ifstream file(dataFileName.c_str());
    std::string line;
    std::string key;
    std::string value;
    std::string delimiter = ",";
    int count = 0;

    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << dataFileName << std::endl;
        return false;
    }

    while (std::getline(file, line)) {
        if (count == 0) {
            count++;
            continue;
        }

        size_t pos = line.find(delimiter);

        if (pos == std::string::npos) {
            std::cerr << "Error: invalid CSV format" << std::endl;
            return false;
        }

        key = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        value = line;

        // Converta a string para float usando strtod (C++98)
        char* end;
        float floatValue = static_cast<float>(strtod(value.c_str(), &end));

        if (*end != '\0') {
            std::cerr << "Error: invalid value format" << std::endl;
            return false;
        }

        dataMap[key] = floatValue;
    }

    file.close();
    return true;
}



#include <cstdlib> // Para atof

// ...

float BitCoinExchange::convertToFloat(const std::string& value) {
    float result;
    char* end;

    result = static_cast<float>(std::strtod(value.c_str(), &end));

    if (*end != '\0') {
        std::cerr << "Error: invalid value format" << std::endl;
        return -1.0f;
    }

    return result;
}


std::pair<std::string, float> BitCoinExchange::makePair(const std::string& pair){
    std::size_t pos = pair.find("|");
    if (pos != std::string::npos) {
        std::string firstPart = pair.substr(0, pos);
        std::string secondPart = pair.substr(pos + 1);

        float floatValue = static_cast<float>(std::atof(secondPart.c_str()));
        
        std::pair<std::string, float> resultPair(firstPart, floatValue);
        return resultPair;
    } else {
        return std::make_pair("", 0.0f);
    }
}

#include <cctype>
#include <sstream>

std::string BitCoinExchange::trim(const std::string& str) {
    std::string result = str;
    size_t start = 0;
    size_t end = result.length();

    // Remova espaços em branco no início
    while (start < end && std::isspace(result[start])) {
        start++;
    }

    // Remova espaços em branco no final
    while (end > start && std::isspace(result[end - 1])) {
        end--;
    }

    // Substring sem espaços em branco no início e no final
    return result.substr(start, end - start);
}

void BitCoinExchange::calculate(const std::map<std::string, float>& csv, const std::string& file) {
    std::ifstream myFile(file.c_str());
    std::string fileStr;

    if (!myFile.is_open()) {
        std::cerr << "Could not open " << file << std::endl;
        return;
    }

    // Pule a primeira linha, que contém cabeçalhos
    std::getline(myFile, fileStr);

    while (std::getline(myFile, fileStr)) {
        // Encontre a posição do caractere '|'
        size_t pos = fileStr.find('|');

        if (pos != std::string::npos) {
            // Divida a linha em duas partes
            std::string datePart = fileStr.substr(0, pos);
            std::string valuePart = fileStr.substr(pos + 1);

            // Remova espaços em branco no início e no final das partes
            datePart = trim(datePart);
            valuePart = trim(valuePart);

            // Verifique se a data existe no mapa
            if (csv.find(datePart) != csv.end()) {
                // Converta o valor para float
                float floatValue = convertToFloat(valuePart);

                if (floatValue >= 0) {
                    float result = csv.at(datePart) * floatValue;
                    std::cout << datePart << " -> " << result << " = " << valuePart << std::endl;
                } else {
                    std::cerr << "Error: negative value for date " << datePart << ": " << valuePart << std::endl;
                }
            } else {
                std::cerr << "Error: date not found in data: " << datePart << std::endl;
            }
        } else {
            std::cerr << "Error: invalid input format in line: " << fileStr << std::endl;
        }
    }
    myFile.close();
}

int BitCoinExchange::openFile(std::ifstream& file, const std::string& fileName) {
    file.open(fileName.c_str());

    if (!file.is_open()) {
        std::cerr << "Could not open " << fileName << std::endl;
        return -1;
    }
    return 0;
}


bool BitCoinExchange::isValidDateFormat(const std::string& date) {
    // Verifica se a data tem o formato esperado "YYYY-MM-DD"
    if (date.size() != 10) {
        std::cerr << "Error: invalid date format" << std::endl;
        return false;
    }

    if (date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: invalid date format" << std::endl;
        return false;
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (!isValidYear(year) || !isValidMonth(month) || !isValidDay(day)) {
        std::cerr << "Error: invalid date" << std::endl;
        return false;
    }

    return true;
}

bool BitCoinExchange::isValidYear(int year) {
    if (year < 2009 || year > 2018) {
        std::cerr << "Error: invalid year" << std::endl;
        return false;
    }
    return true;
}

bool BitCoinExchange::isValidMonth(int month) {
    if (month < 1 || month > 12) {
        std::cerr << "Error: invalid month" << std::endl;
        return false;
    }
    return true;
}

bool BitCoinExchange::isValidDay(int day) {
    if (day < 1 || day > 31) {
        std::cerr << "Error: invalid day" << std::endl;
        return false;
    }
    return true;
}

bool BitCoinExchange::isValidValue(float value) {
    return (value >= 0 && value <= 1000);
}

void BitCoinExchange::printValue(const std::map<std::string, float>& dataMap, const std::string& inputStr) {
    std::map<std::string, float>::const_iterator it;

    it = dataMap.find(inputStr);
    if (it != dataMap.end()) {
        std::cout << it->second << std::endl;
    } else {
        std::cerr << "Error: invalid input" << std::endl;
    }
}
