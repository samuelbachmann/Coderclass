#include <iostream>

int amountOfPlates(){
    int input;
    if(std::cin >> input){
        if (input > 0){
            return input;
        }
        else{
            throw std::runtime_error("invalid input"); 
        } 
    }else{
        throw std::runtime_error("invalid input");
    }
}

void towerOfHanio(int plates){
    std::cout << plates;
    if(plates % 2){
        
    }else{

    }
}


int main(){
    int amount;
    std::cout << "How many disks should the tower consist of? ";
    try{
        amount = amountOfPlates();
    }catch(std::runtime_error& excpt){
        std::cout << excpt.what() << std::endl;
        return 1;
    }
    towerOfHanio(amount);
}