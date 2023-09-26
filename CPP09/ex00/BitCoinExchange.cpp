#include "BitCoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "[BitcoinExchange] create!!!" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "[BitcoinExchange] delete!!!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    std::cout << "[BitcoinExchange] copy!!!" << std::endl;
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    std::cout << "[BitcoinExchange] operator=!!!" << std::endl;
    if (this != &rhs)
    {
        this->db = rhs.db;
    }
    return *this;
}

void BitcoinExchange::LoadData()
{
    std::ifstream file;
    std::string line;

    try {
        file.open("./data.csv");
        if (!file.is_open()) {
            throw std::runtime_error("Error to open file");
        }

        file >> line;
        while (!file.eof()) {
            file >> line;
            std::string date = line.substr(0, line.find(','));
            std::string price = line.substr(line.find(',') + 1, line.length());
            this->db.insert(std::make_pair(date.substr(0, 10).erase(4, 1).erase(6, 1), strtod(price.c_str(), NULL)));
        }

        file.close();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void BitcoinExchange::PrintData()
{
    std::map<std::string, double>::iterator it = this->db.begin();
    while (it != this->db.end())
    {
        std::cout << it->first << " " << it->second << std::endl;
        ++it;
    }
}

bool isNumeric(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && (isdigit(*it) || *it == '.')) {
        ++it;
    }
    return it == str.end();
}

void BitcoinExchange::InputHandler(std::string filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cout << "Error: Unable to open file" << std::endl;
        return;
    }

    std::string line;

    std::getline(file, line);
    if (line != "date | value")
    {
        std::cerr << "Error: Expected 'date | value'" << std::endl;
        file.close();
        return;
    }

    while (std::getline(file, line))
    {
        if (line.length() < 14 || CountWords(line) != 2)
        {
            std::cerr << "Error: " << line << std::endl;
            continue;
        }

        std::string year = line.substr(0, 4);
        std::string month = line.substr(5, 2);
        std::string day = line.substr(8, 2);
        std::string price = line.substr(13, line.length());

        if (!isNumeric(year) || !isNumeric(month) || !isNumeric(day) || !isNumeric(price))
        {
            std::cerr << "Error: " << line << std::endl;
            continue;
        }

        int day_int = atoi(day.c_str());
        int month_int = atoi(month.c_str());
        int year_int = atoi(year.c_str());
        double price_double = strtod(price.c_str(), NULL);

        if (ParseInput(year_int, month_int, day_int, price_double, line) != -1)
        {
            std::ostringstream oss;
            oss << year_int;
            if (month_int < 10)
                oss << "0";
            oss << month_int;
            if (day_int < 10)
                oss << "0";
            oss << day_int;
            std::string fulldate = oss.str();
            PrintExchangeInfo(fulldate, price_double);
        }
    }

    file.close();
}

int BitcoinExchange::ParseInput(int year, int month, int day, double value, std::string line)
{
    if (line.substr(4, 1) != "-" || line.substr(7, 1) != "-")
    {
        std::cerr << "Error: Invalid text format" << std::endl;
        return -1;
    }

    size_t pos = line.find('|');
    if (line[pos - 1] != ' ' || line[pos + 1] != ' ')
    {
        std::cerr << "Error: Invalid pipe" << std::endl;
        return -1;
    }

    if (value < 0.00 || value > 1000.00)
    {
        std::cerr << "Error: Value outside the permitted range" << std::endl;
        return -1;
    }

    if (year < 2009 || month < 1 || month > 12)
    {
        std::cerr << "Error: Date is invalid" << std::endl;
        return -1;
    }

    int month_limits[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day > month_limits[month - 1] || day < 1)
    {
        std::cerr << "Error: Non-existent date" << std::endl;
        return -1;
    }

    return 0;
}

void BitcoinExchange::PrintExchangeInfo(std::string date, double exchangeRate)
{
    if (date < this->db.begin()->first)
    {
        std::cout << "Error: Date is earlier than the earliest date in the database." << std::endl;
        return;
    }

    std::map<std::string, double>::iterator it = this->db.upper_bound(date);
    it--;

    std::string formattedDate = date;
    formattedDate.insert(4, "-").insert(7, "-");

    double result = exchangeRate * it->second;

    std::cout << formattedDate << " => " << exchangeRate << " = " << std::fixed << std::setprecision(2) << result << std::endl;
}

int BitcoinExchange::CountWords(std::string line)
{
    std::string delimiter = " ";
    size_t pos = 0;
    int wordCount = 0;

    while ((pos = line.find(delimiter)) != std::string::npos) {
        wordCount++;
        line.erase(0, pos + delimiter.length());
    }

    return wordCount;
}
