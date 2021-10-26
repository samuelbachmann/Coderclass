#include <iostream>
#include <sstream>
#include <cmath>

float first_solution, second_solution;

float discriminant(float aCal, float bCal, float cCal){
    float dCal = (bCal * bCal) - 4 * aCal * cCal;
    return dCal;
}

float calculateSolution(float a_cal, float b_cal, float d_cal){
    first_solution = (-b_cal + sqrt(d_cal)) / (2 * a_cal );
    second_solution = (-b_cal - sqrt(d_cal)) / (2 * a_cal);

    return 0;
}

int main(){
    float a, b, c, d;
    std::string expression;
    std::cout << "Please enter the values of a, b, and c: ";
    std::getline(std::cin, expression);
    std::istringstream splitString(expression);
    splitString >> a;
    splitString >> b;
    splitString >> c;
 
    d = discriminant(a, b, c);
    calculateSolution(a, b, d);

    if(d > 0){
        std::cout << "There are 2 solutions. \n";
        std::cout << "The solutions are: " << first_solution << " and " << second_solution;
    } if(d == 0){
        std::cout << "There is 1 solution.\n";
        std::cout << "The solution is: " << first_solution;
    } if(d < 0){
        std::cout << "There is no solution.";
    }

    return 0;
}