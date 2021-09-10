#include <iostream>
#include <sstream>
int main(){
    int playing = 1;
    double answer, numberOne, numberTwo;
    char symbol;
    while(playing){
        std::string expression;
        std::cout << "Enter the expression: ";
        std::getline(std::cin, expression);
        std:: istringstream splitString(expression);
        splitString >> symbol;
        splitString >> numberOne;
        splitString >> numberTwo;
        switch(symbol) {
            case '+':
                answer = numberOne + numberTwo;
                break;
            case '-':
                answer = numberOne - numberTwo;
                break;
            case '*':
                answer = numberOne * numberTwo;
                break;
            case '/':
                answer = numberOne / numberTwo;
                break;
            case 'q':
                playing = 0;
                return 0;
                
        }
        std::cout << numberOne << " " << symbol << " " << numberTwo << " = " << answer << "\n";
    }
    return 0;
}