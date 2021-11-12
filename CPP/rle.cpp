#include <iostream>
#include <regex>

void checkIfLetter(const std::string userInput){
    if(!isalpha(userInput)){
        throw std::runtime_error("invalid input");
    }
}


int main(){
    std::string input;
    std::cout << "Enter the data to be compressed: ";
    std::cin >> input;

    try{
        checkIfLetter(input);
        checkIfLower(input);
    }catch(std::runtime_error& excpt){
        std::cout << "error: " << excpt.what() << std::endl;
        return 1;
    }
}