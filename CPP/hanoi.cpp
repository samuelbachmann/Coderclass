#include <iostream>

int amountOfPlates(){
    int input;
    if(std::cin >> input){
        if (input > 0){
            return input;
        }
        else{
            throw std::runtime_error("\ninvalid input."); 
        } 
    }else{
        throw std::runtime_error("\ninvalid input.");
    }
}

void towerOfHanio(int plates, char from_tower, char to_tower, char other_tower){

    if(plates == 1){
        std::cout << "\nMove disk 1 from " << from_tower <<" to " << to_tower << ".";
        return;
    }
    towerOfHanio(plates - 1, from_tower, other_tower, to_tower);
    std::cout << "\nMove disk " << plates << " from " << from_tower << " to " << to_tower << ".";
    towerOfHanio(plates - 1, other_tower, to_tower, from_tower);
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
    towerOfHanio(amount, 'A', 'C', 'B');
}