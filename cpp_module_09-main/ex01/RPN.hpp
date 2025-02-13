#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
public:
    // Constructor ve Destructor
    RPN();
    ~RPN();

    // Ana fonksiyon: Ters Polonya Notasyonu ifadesini değerlendirir
    int evaluate(const std::string& expression);

private:
    // Yardımcı fonksiyonlar
    bool isOperator(char c);                  // Verilen karakterin bir operatör olup olmadığını kontrol eder
    int applyOperation(int a, int b, char op); // Operatörle iki sayıyı işler
};

#endif // RPN_HPP
