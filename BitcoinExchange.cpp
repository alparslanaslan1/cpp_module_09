#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::~BitcoinExchange(){};

void BitcoinExchange::bitData(std::string dataFile){
    std::ifstream bitDataFile(dataFile.c_str());

    if (!bitDataFile.is_open()){
        return ;
    }

    std::string line;
    std::getline(bitDataFile, line);
    //ilk lişne string mi kontrolü yap;

    int i;
    while(std::getline(bitDataFile, line)){
        i = line.find(",");

        unsigned int date = BitcoinExchange::strToDateValue(line.substr(0,i));
        
        std::cout<< date<<std::endl; 
    }
}

unsigned int BitcoinExchange::strToDateValue(std::string value){

    size_t pos;
    unsigned int result;
    while ((pos = value.find("-")) != std::string::npos){
        value.erase(pos, 1);
    }
    std::stringstream dateValue(value);

    dateValue >> result;

    if (dateValue.fail() || !dateValue.eof()){
        std::cout << "baba naber" << std::endl;
        return(0);
    }
    return result;
    

}