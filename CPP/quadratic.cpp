#include <iostream>
#include <sstream>
#include <cmath>

int main(){
    float a, b, c, d, first_solution, second_solution, solution;
    std::string expression;
    std::cout << "Please enter the values of a, b and c: ";
    std::getline(std::cin, expression);
    std:: istringstream splitString(expression);
    splitString >> a;
    splitString >> b;
    splitString >> c;
    
    d = pow(b,2) - 4 * b * c;

    if(d > 0){
        first_solution = (b + sqrt(d)) / (a * 2);
        second_solution = (b - sqrt(d)) / (a * 2);
        std::cout << "There are 2 solutions.";
        std::cout << "The solutions are: " << first_solution << " and " << second_solution;
    } else if(d == 0){
        solution = b / (a * 2);
        std::cout << "There is 1 solution.";
        std::cout << "The solution is: " << solution;
    } else if(d < 0){
        std::cout << "There is no solutions.";
    }

    return 0;
}
