#include "BitcoinExchange.hpp"



#include <cstdlib>
BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::~BitcoinExchange(){};

void BitcoinExchange::bitData(std::string dataFile) {
    std::ifstream bitDataFile(dataFile.c_str());

    if (!bitDataFile.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(bitDataFile, line);

    std::string::size_type i;
    std::map<unsigned int, float>::iterator it;
    while (std::getline(bitDataFile, line)) {
        i = line.find(",");

        if (i == std::string::npos) {
            std::cerr << "Error: Invalid line format -> " << line << std::endl;
            continue;
        }

        std::string datePart = line.substr(0, i);
        std::string pricePart = line.substr(i + 1);

        unsigned int date = BitcoinExchange::dataDateValue(datePart);
        float price = BitcoinExchange::dataPriceValue(pricePart);

        dataBase.insert(std::make_pair(date, price)); 

    }
}

unsigned int BitcoinExchange::dataDateValue(std::string &value) {
    size_t pos;
    while ((pos = value.find("-")) != std::string::npos) {
        value.erase(pos, 1);
    }

    std::stringstream dateValue(value);
    unsigned int result = 0;

    dateValue >> result;

    if (dateValue.fail() || !dateValue.eof()) {
        std::cerr << "baba hata -> " << value << std::endl;
        return 0;
    }
    return result;
}


float BitcoinExchange::dataPriceValue(std::string &value) {
    std::stringstream priceValue(value);
    float price = 0;

    priceValue >> price;

    if (priceValue.fail() || !priceValue.eof()) {
        std::cerr << "hataError: Invalid price format -> " << value << std::endl;
        return 0;
    }
    return price;
}


void BitcoinExchange::inputData(std::string inputFile) {
    std::ifstream inputDataFile(inputFile.c_str());

    if (!inputDataFile.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(inputDataFile, line);

    std::string::size_type i;
    std::string datePart;
    std::string pricePart;
    while (std::getline(inputDataFile, line)) {
        i = line.find("|");

        if (i == std::string::npos) {
            std::cerr << "Error: Invalid line format -> " << line << std::endl;
            continue;
        }

        datePart = line.substr(0, i);
        pricePart = line.substr(i + 1);

        unsigned int date = BitcoinExchange::inputDateValue(datePart);
        float amount = BitcoinExchange::inputPriceValue(pricePart);
        inputBase.insert(std::make_pair(date, amount));

        // if (!dateControl(date)) {
        //     //std::cerr << "Error: bad input => " << date << std::endl;
        //     continue;
        // }

        // if (!amountControl(amount)) {
        //     continue;
        // }

    }

    // Map'i yazdır ve eşleşen ya da en yakın değeri bul
    std::multimap<unsigned int, float>::iterator itInput;
    for (itInput = inputBase.begin(); itInput != inputBase.end(); ++itInput) {
        unsigned int date1 = itInput->first;
        float closestValue = getClosestValue(date1);
        if (!dateControl(itInput->first)) {
            std::cerr << "Error: bad input => " << itInput->first << std::endl;
            continue;
        }

        if (!amountControl(itInput->second)) {
            continue;
        }        
        if (closestValue != -1.0f) {
            std::cout << itInput->first / 10000 << "-" << (itInput->first / 100) % 100 << "-" << itInput->first % 100 << " => " << itInput->second << " = " << itInput->second * closestValue << std::endl;
        }
    }
}



unsigned int BitcoinExchange::inputDateValue(std::string &value) {
    size_t pos;
    while ((pos = value.find("-")) != std::string::npos) {
        value.erase(pos, 1);
    }

    std::stringstream dateValue(value);
    unsigned int result = 0;

    dateValue >> result;

    if (dateValue.fail() || !dateValue.eof()) {
        std::cerr << "baba3213123 hata 234-> " << value << std::endl;
        return 0;
    }
    return result;
}

float BitcoinExchange::inputPriceValue(std::string &value){
        std::stringstream priceValue(value);
    float amount = 0;

    priceValue >> amount;

    if (priceValue.fail() || !priceValue.eof()) {
        std::cerr << "hataError: Invalid price format -> " << amount << std::endl;
        return 0;
    }
    return amount;
}


bool BitcoinExchange::dateControl(unsigned int date) {
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;

    if (year < 2009 || year > 2140) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    int maxDays;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDays = 31;
            break;
        case 4: case 6: case 9: case 11:
            maxDays = 30;
            break;
        case 2:
            maxDays = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
            break;
        default:
            return false;
    }

    if (day < 1 || day > maxDays) {
        return false;
    }

    return true;
}

bool BitcoinExchange::amountControl(float &amount){

    if  (amount < 0){
      std::cerr << "Error: not a positive number. " << std::endl;
        return 0;
    }

    if (amount > 1000){
        std::cerr << "Error: too large a number. " << std::endl;
        return 0;
    }
    return(1);
}


float BitcoinExchange::getClosestValue(unsigned int date) {
    // dataBase'deki tarihi kontrol et
    std::map<unsigned int, float>::iterator it = dataBase.lower_bound(date);

    if (it != dataBase.end() && it->first == date) {
        // Eğer tarih bulunduysa, o tarihin değerini döndür
        return it->second;
    }

    if (it == dataBase.begin()) {
        // Eğer tarihten önce bir tarih yoksa, hata ver
        std::cerr << "Error: No earlier date available for " << date << std::endl;
        return -1.0f; // Hata değeri
    }

    // Bir önceki tarihe git
    --it;
    return it->second;
}
