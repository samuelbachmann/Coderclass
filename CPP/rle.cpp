#include <iostream>
#include <regex>
#include <vector>

void checkIfLetter(std::string userInput){
    if(!std::regex_match(userInput, std::regex("^[a-z]*$"))){
        throw std::runtime_error("invalid input");
    }
}

void countLetter(std::string userInput, std::vector<int>& countOfLetters, std::vector<char>& letters){
    char letterCharater = userInput[0];
    int count = 0;

    for(int c = 0; c < userInput.size(); c++){
        if(userInput.at(c) ==  letterCharater){
            count += 1;
        }else{
            countOfLetters.push_back(count);
            letters.push_back(letterCharater);
            count = 1;
            letterCharater = userInput.at(c);
        }
    }
    
    if(count){
        countOfLetters.push_back(count);
        letters.push_back(letterCharater);
    }
}

int main(){
    std::string input;
    std::cout << "Enter the data to be compressed: ";
    std::cin >> input;
    std::vector<int> countOfLetters;
    std::vector<char> letters;

    try{
        checkIfLetter(input);
        countLetter(input, countOfLetters, letters);
    }catch(std::runtime_error& excpt){
        std::cout << "error: " << excpt.what() << std::endl;
        return 1;
    }

    std::cout << ("The compressed data is: ");
    for(int i= 0; i < letters.size(); i++){
        std::cout << countOfLetters.at(i) << letters.at(i);
    }

    return 0;
}