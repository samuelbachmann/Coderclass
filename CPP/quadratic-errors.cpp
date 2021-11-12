#include <iostream>
#include <sstream>
#include <cmath>

double discriminant(double aCal, double bCal, double cCal){
    double dCal = (bCal * bCal) - 4 * aCal * cCal;
    return dCal;
}

double calculateFirstSolution(double a_cal, double b_cal, double d_cal){
    double first_solution = (-b_cal + sqrt(d_cal)) / (2 * a_cal );
    return first_solution;
}

double calculateSecondSolution(double a_cal, double b_cal, double d_cal){
    double second_solution = (-b_cal - sqrt(d_cal)) / (2 * a_cal);
    return second_solution;
}

double checkInput(){
    double input;
    if(std::cin >> input){
        return input;
    }
    throw std::runtime_error("Malformed user input");
}

int main(){
    double a, b, c, d;
    std::cout << "Please enter the values of a, b, and c: ";
    try{
        a = checkInput();
        if(a == 0){
            throw std::runtime_error("a must not be zero");
        } 
        b = checkInput();
        c = checkInput();
    }catch(std::runtime_error& excpt){
        std::cout << "An error occurred: " << excpt.what() << std::endl;
        return 1;
    }

    d = discriminant(a, b, c);

    if(d > 0){
        std::cout << "There are 2 solutions. \n";
        std::cout << "The solutions are: " << calculateFirstSolution(a, b, d) << " and " << calculateSecondSolution(a, b, d);
    } else if(d == 0){
        std::cout << "There is 1 solution.\n";
        std::cout << "The solution is: " << calculateFirstSolution(a, b, d);
    } else if(d < 0){
        std::cout << "There is no solution.";
    }

    return 0;
} 