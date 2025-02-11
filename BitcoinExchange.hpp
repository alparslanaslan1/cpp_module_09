#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange
{
    private:
        std::map<unsigned int, float> dataBase;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void bitData(std::string dataFile);
        static unsigned int strToDateValue(std::string value);




};

#endif