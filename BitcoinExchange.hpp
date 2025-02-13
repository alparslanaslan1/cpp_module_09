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

    public:
        std::map<unsigned int, float> dataBase;
        std::multimap<unsigned int, float> inputBase;
        BitcoinExchange();
        ~BitcoinExchange();
        void bitData(std::string dataFile);
        void inputData(std::string inputFile);

        unsigned int dataDateValue(std::string &value);
        float dataPriceValue(std::string &value);


        static unsigned int inputDateValue(std::string &value);
        float inputPriceValue(std::string &value);

        bool dateControl(unsigned int date);
        bool amountControl(float &amount);

        float getClosestValue(unsigned int date);
};

#endif