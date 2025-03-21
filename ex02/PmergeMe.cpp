#include "PmergeMe.hpp"
#include <sstream>
#include <cstdlib> 
#include <iomanip>

PmergeMe::PmergeMe() : _vectorProcessingTime(0), _dequeProcessingTime(0){}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        int number = std::atoi(argv[i]);
        if (number <= 0) {
            throw std::runtime_error("Error");
        }
        _unsortedVector.push_back(number);
        _unsortedDeque.push_back(number);
    }
    displayResults();
}

void PmergeMe::displayResults() {
    printContainer("Before:", _unsortedVector);
    sortVector(_unsortedVector);
    sortDeque(_unsortedDeque);

    std::cout << "Time to process a range of " << _unsortedVector.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << _vectorProcessingTime  << " us" << std::endl;

    std::cout << "Time to process a range of " << _unsortedDeque.size()
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) 
              << _dequeProcessingTime << " us" << std::endl;
}

// Vector
void PmergeMe::sortVector(const std::vector<int>& input)
{
    std::vector<int> container = input;
    
    clock_t beforeTime = clock();
    mergeInsertVector(container);
    clock_t endTime = clock();
    
    _vectorProcessingTime = static_cast<double>(endTime - beforeTime) / CLOCKS_PER_SEC * 1000;
    printContainer("After: ", container);
}

void PmergeMe::sortDeque(const std::deque<int>& input) {
    std::deque<int> container = input;

    clock_t beforeTime = clock();
    mergeInsertDeque(container);
    clock_t endTime = clock();

    _dequeProcessingTime = static_cast<double>(endTime - beforeTime) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::mergeInsertVector(std::vector<int> &container)
{
    if (container.size() <= 1)
        return;
    
    std::vector<int>::iterator mid = container.begin()  + container.size() / 2;

    std::vector<int> left(container.begin(), mid);
    std::vector<int> right(mid, container.end());

    mergeInsertVector(left);
    mergeInsertVector(right);

    sortingVector(left, right, container);
}

void PmergeMe::mergeInsertDeque(std::deque<int> &container)
{
    if (container.size() <= 1)
        return;
    
    std::deque<int>::iterator mid = container.begin()  + container.size() / 2;

    std::deque<int> left(container.begin(), mid);
    std::deque<int> right(mid, container.end());

    mergeInsertDeque(left);
    mergeInsertDeque(right);

    sortingDeque(left, right, container);
}

void PmergeMe::sortingVector(std::vector<int> &left, std::vector<int> &right, std::vector<int> &container)
{
    size_t i ,j, k;
    i = j = k = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[i])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while (i < left.size()) {
        container[k++] = left[i++];
    }
    while (j < right.size()) {
        container[k++] = right[j++];
    }

}

void PmergeMe::sortingDeque(std::deque<int> &left, std::deque<int> &right, std::deque<int> &container)
{
    size_t i ,j, k;
    i = j = k = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[i])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while (i < left.size()) {
        container[k++] = left[i++];
    }
    while (j < right.size()) {
        container[k++] = right[j++];
    }

}

// Deque


// Print vector
void PmergeMe::printContainer(const std::string& message, const std::vector<int>& container) {
    std::cout << message << " ";
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Print deque
void PmergeMe::printContainer(const std::string& message, const std::deque<int>& container) {
    std::cout << message << " ";
    for (std::deque<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
