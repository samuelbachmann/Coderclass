#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(){
    int height, width;
    
    height = 5 *2 +1;
    width = 6;
    std::vector<std::string> currentMase(height);

    for(int i = 0; i < height; i++){
        if(i%2 != 0){
            for(int c = 0; c < width; c++){
                // std::cout << i << "\n";
                currentMase.at(i) += "|   ";
                if(c +1 == width){
                    currentMase.at(i) += "|";
                }
            }
        }else{
            for(int c = 0; c < width; c++){
                // std::cout << i << "\n";
                currentMase.at(i) += "+---";
                if(c +1 == width){
                    currentMase.at(i) += "+";
                }
            }
        }
    }

    for(int i = 0; i < currentMase.size(); i++){
        std::cout << currentMase.at(i) << "\n";
    }
}