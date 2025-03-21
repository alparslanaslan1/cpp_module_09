#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <ctime>  

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void sortVector(const std::vector<int>& input);
    void sortDeque(const std::deque<int>& input);
    void parseInput(int argc, char** argv);
    void displayResults();
    void sortingVector(std::vector<int> &left, std::vector<int> &right, std::vector<int> &container);
    void sortingDeque(std::deque<int> &left, std::deque<int> &right, std::deque<int> &container);

private:
    std::vector<int> _unsortedVector;
    std::deque<int>  _unsortedDeque;

    void printContainer(const std::string& message, const std::vector<int>& container);
    void printContainer(const std::string& message, const std::deque<int>& container);

    void mergeInsertVector(std::vector<int> &container);
    void mergeInsertDeque(std::deque<int> &container);


    double _vectorProcessingTime;
    double _dequeProcessingTime;




};

#endif 

