#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:

    public:
        std::map<std::string, float> dataBase;
        BitcoinExchange();
        ~BitcoinExchange();
        void btcData(std::string dataFile);
        void inputData(std::string inputFile);

        float dataToBtcValue(std::string value);

        std::string removeWhiteSpace(const std::string &value);
        bool dateControl(std::string &date);
        bool amountControl(float amount);
        bool isLeapYear(int year);
        float findValue(std::string &date);

};

#endif