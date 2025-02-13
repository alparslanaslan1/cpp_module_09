#include "PmergeMe.hpp"
#include <sstream>
#include <cstdlib> // std::atoi

// Constructor
PmergeMe::PmergeMe() : _vectorProcessingTime(0), _dequeProcessingTime(0) {}

// Destructor
PmergeMe::~PmergeMe() {}

// Mikro saniye ölçümü
long PmergeMe::getCurrentTimeInMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

// Girdi verisini parse et
void PmergeMe::parseInput(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        int number = std::atoi(argv[i]);
        if (number <= 0) {
            throw std::runtime_error("Error");
        }
        _unsortedVector.push_back(number);
        _unsortedDeque.push_back(number);
    }
}

// Merge-insert sort algoritması (vector)
void PmergeMe::sortWithVector(const std::vector<int>& input) {
    std::vector<int> container = input;

    long start = getCurrentTimeInMicroseconds();
    mergeInsertSort(container);
    long end = getCurrentTimeInMicroseconds();

    _vectorProcessingTime = static_cast<double>(end - start);
    printContainer("After:", container);
}

// Merge-insert sort algoritması (deque)
void PmergeMe::sortWithDeque(const std::deque<int>& input) {
    std::deque<int> container = input;

    long start = getCurrentTimeInMicroseconds();
    mergeInsertSort(container);
    long end = getCurrentTimeInMicroseconds();

    _dequeProcessingTime = static_cast<double>(end - start);
}

// Sonuçları yazdır
void PmergeMe::displayResults() {
    printContainer("Before:", _unsortedVector);
    sortWithVector(_unsortedVector);
    sortWithDeque(_unsortedDeque);

    std::cout << "Time to process a range of " << _unsortedVector.size()
              << " elements with std::vector : " << _vectorProcessingTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _unsortedDeque.size()
              << " elements with std::deque : " << _dequeProcessingTime << " us" << std::endl;
}

// Konteyneri yazdır (vector)
void PmergeMe::printContainer(const std::string& message, const std::vector<int>& container) {
    std::cout << message << " ";
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Konteyneri yazdır (deque)
void PmergeMe::printContainer(const std::string& message, const std::deque<int>& container) {
    std::cout << message << " ";
    for (std::deque<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
