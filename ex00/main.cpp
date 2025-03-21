#include "BitcoinExchange.hpp"

int main(int ac, char **av){

    if (ac != 2)
    {
        std::cout << "bad input" << std::endl;
        return (0);
    }

    BitcoinExchange bE;
    bE.btcData("data.csv");
    bE.inputData(av[1]);
    


}