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

        // Map içindeki tüm elemanları yazdır
        // for (it = dataBase.begin(); it != dataBase.end(); ++it) {
        //     std::cout << "Key (Date): " << it->first << ", Value (Price): " << it->second << std::endl;
        // }
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
    std::map<unsigned int, float>::iterator itInput;
    while (std::getline(inputDataFile, line)) {
        i = line.find("|");

        if (i == std::string::npos) {
            std::cerr << "Error: Invalid line format -> " << line << std::endl;
            continue;
        }

        std::string datePart = line.substr(0, i);
        std::string pricePart = line.substr(i + 1);

        unsigned int date = BitcoinExchange::inputDateValue(datePart);
        float amount = BitcoinExchange::inputPriceValue(pricePart);

        inputBase.insert(std::make_pair(date, amount)); 

        }
        for (itInput = inputBase.begin(); itInput != inputBase.end(); ++itInput) {
            std::cout << "Key (Date): " << itInput->first << ", Value (Price): " << itInput->second << std::endl;
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

void dateControl(unsigned int &date){


}