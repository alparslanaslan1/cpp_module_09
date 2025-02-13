#include "RPN.hpp"
#include <cstdlib> // std::atoi

// Constructor
RPN::RPN() {}

// Destructor
RPN::~RPN() {}

// Operatör olup olmadığını kontrol eder
bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Operasyonu gerçekleştirir
int RPN::applyOperation(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("Invalid operator");
    }
}

// Ters Polonya Notasyonu ifadesini değerlendirir
int RPN::evaluate(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        // Eğer token bir operatörse
        if (token.size() == 1 && isOperator(token[0])) {
            if (stack.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            stack.push(applyOperation(a, b, token[0]));
        } 
        // Eğer token bir sayıya karşılık geliyorsa
        else {
            int number = std::atoi(token.c_str());
            if (number >= 10) {
                throw std::runtime_error("Number out of range");
            }
            stack.push(number);
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }
    return stack.top();
}
