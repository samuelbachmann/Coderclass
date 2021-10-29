#include <iostream>
#include <sstream>
#include <cmath>

float discriminant(float aCal, float bCal, float cCal){
    float dCal = (bCal * bCal) - 4 * aCal * cCal;
    return dCal;
}

float calculateSolution(float a_cal, float b_cal, float d_cal){
    float first_solution, second_solution;
    float first_solution = (-b_cal + sqrt(d_cal)) / (2 * a_cal );
    float second_solution = (-b_cal - sqrt(d_cal)) / (2 * a_cal);
    std::cout << first_solution << second_solution << "\n";
    return first_solution, second_solution;
}

int main(){
    float a, b, c, d, calcOneSolution, calcTwoSolution;
    std::string expression;
    std::cout << "Please enter the values of a, b, and c: ";
    std::getline(std::cin, expression);
    std::istringstream splitString(expression);
    splitString >> a;
    splitString >> b;
    splitString >> c;
 
    d = discriminant(a, b, c);
    calcOneSolution, calcTwoSolution = calculateSolution(a, b, d);

    if(d > 0){
        std::cout << "There are 2 solutions.\n";
        std::cout << "The solutions are: " << calcOneSolution << " and " << calcTwoSolution;
    } if(d == 0){
        std::cout << "There is 1 solution.\n";
        std::cout << "The solution is: " << calcOneSolution;
    } if(d < 0){
        std::cout << "There is no solution.";
    }

    return 0;
}