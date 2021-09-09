#include <iostream>

int main(){
    std::string expression;
    std::cout << "Enter the expression: ";
    std::getline(std::cin, expression);
    
    std::string symbol = expression.substr(0, expression.find(" "));
    expression = expression.erase(0, symbol.length() + 1);
    std::string number1 = expression.substr(0, expression.find(" "));
    expression = expression.erase(0, number1.length() + 1);
    std::string number2 = expression.substr(0, expression.find(" "));

    std::cout << number1 << " " << symbol << " " << number2;
 
    return 0;
}