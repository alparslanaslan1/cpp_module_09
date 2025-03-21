#include "BitcoinExchange.hpp"



BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::~BitcoinExchange(){};

void BitcoinExchange::btcData(std::string dataFile) {
    std::ifstream btcDataFile(dataFile.c_str());

    if (!btcDataFile.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(btcDataFile, line);

    std::string::size_type i;
    std::multimap<std::string, float>::iterator it;
    while (std::getline(btcDataFile, line)) {
        i = line.find(",");

        if (i == std::string::npos) {
            std::cerr << "Error: Invalid line format -> " << line << std::endl;
            continue;
        }      
        std::string datePart = line.substr(0, i);
        std::string pricePart = line.substr(i + 1);

        float price = BitcoinExchange::dataToBtcValue(pricePart);

        dataBase.insert(std::multimap<std::string, float>::value_type(datePart, price)); 
    }

}   


void BitcoinExchange::inputData(std::string inputFile){
    
    std::ifstream inputDataFile(inputFile.c_str());
    if (!inputDataFile.is_open()){
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }
    std::string line;
    std::string::size_type i;

    std::getline(inputDataFile, line);
    line = BitcoinExchange::removeWhiteSpace(line);

    if (line != "date|value"){
        std::cout << "Error: desired format => date | value. " <<std::endl;
        return;
    }

    std::string datePart;
    std::string amountPart;
    float amount;

    while (std::getline(inputDataFile, line)){
        line = BitcoinExchange::removeWhiteSpace(line);
        i = line.find("|");

        if (i == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        datePart = line.substr(0, i);
        amountPart = line.substr(i + 1);
        amount = BitcoinExchange::dataToBtcValue(amountPart);
        if (!dateControl(datePart)){
            std::cerr << "Error: bad input => " << datePart << std::endl;
            continue;
        }
        if (!amountControl(amount))
            continue;
        std::cout << datePart << " => " << amount << " = " << amount * (findValue(datePart)) << std::endl;
    }

}

float BitcoinExchange::findValue(std::string &date){

    std::map<std::string, float>::const_iterator it = dataBase.lower_bound(date);

    if (it == dataBase.end() ||it->first > date)
        --it;

    return (it->second);
}


bool BitcoinExchange::amountControl(float amount){

    if (amount < 0){
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    else if (amount > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;

}

bool BitcoinExchange::dateControl(std::string &date){

    if (date.size() != 10 || date[4] != '-' || date[7] != '-') 
        return false;
    int year, month, day;

    std::istringstream yearS  (date.substr(0, 4));
    std::istringstream monthS (date.substr(5, 2));
    std::istringstream dayS   (date.substr(8, 2));

    if (!(yearS >> year) || !(monthS >> month) || !(dayS >> day))
        return false;

    if ((year < 2009) || (month < 1 || month > 12))
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) {
        daysInMonth[1] = 29; 
    }
    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    return true;

}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

float BitcoinExchange::dataToBtcValue(std::string value) {
    std::stringstream priceValue(value);
    float price = 0;

    priceValue >> price;

    if (priceValue.fail() || !priceValue.eof()) {
        std::cerr << "Error: Invalid price format -> " << value << std::endl;
        return 0;
    }
    return price;
}

std::string BitcoinExchange::removeWhiteSpace(const std::string& input) {
    std::string result;
    for (std::string::size_type i = 0; i < input.size(); ++i) {
        if (input[i] != ' ' && input[i] != '\t' &&
            input[i] != '\r' && input[i] != '\f' && input[i] != '\v') {
            result += input[i];
        }
    }
    return result;
}