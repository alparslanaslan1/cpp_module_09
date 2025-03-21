#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
public:
    RPN();
    ~RPN();

    int evaluate(const std::string& expression);

private:
    int isOperator(char c);
    int applyOperation(int a, int b, char op);
};

#endif