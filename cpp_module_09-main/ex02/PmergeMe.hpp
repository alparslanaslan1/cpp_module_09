#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm> // std::sort
#include <ctime>     // Zaman ölçümü için
#include <sys/time.h> // Mikro saniye ölçümü için

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void sortWithVector(const std::vector<int>& input);
    void sortWithDeque(const std::deque<int>& input);

    void parseInput(int argc, char** argv);
    void displayResults();

private:
    std::vector<int> _unsortedVector;
    std::deque<int> _unsortedDeque;

    void printContainer(const std::string& message, const std::vector<int>& container);
    void printContainer(const std::string& message, const std::deque<int>& container);

    double _vectorProcessingTime;
    double _dequeProcessingTime;

    // Template merge-insert sort
    template <typename T>
    void mergeInsertSort(T& container) {
        if (container.size() <= 1) {
            return;
        }
        std::sort(container.begin(), container.end());
    }

    long getCurrentTimeInMicroseconds();
};

#endif // PMERGEME_HPP
