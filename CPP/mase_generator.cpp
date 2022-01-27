#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

// one block is 3x5 
//  +---+
//  |   |
//  +---+
// 
//  1 = right
//  2 = left
//  3 = bottom
//  4 = top

class maseGen{
    public:
        std::string createMase(int height, int width,std::vector<std::string>& currentMase);
        std::string mase(int height, int width);
    private:
        std::vector<std::vector<int>> coordinates{
            {1,2,3,1,3},
            {3,2,4,2,2},
            {1,1,1,1,3},
            {3,2,2,2,2},
            {1,1,1,1,3},
        };
};

std::string maseGen::createMase(int height, int width,std::vector<std::string>& currentMase){
    for(int i = 0; i < height * 2; i++){
        if(i % 2 != 0){
            for(int c = 0; c < width; c++){
                currentMase.at(i) += "+---";
                if(c++ == width){
                    currentMase.at(i) += "+\n";
                }
            }
        }else{
            for(int c = 0; c < width; c++){
                currentMase.at(i) += "|   ";
                if(c++ == width){
                    currentMase.at(i) += "|\n";
                }
            }
        }
    }

    for(int c = 0; c < width; c++){
        currentMase.at(height -1) += "+---";
        if(c++ == width){
            currentMase.at(height -1) += "+\n";
        }
    }    


    return "0";
}

std::string maseGen::mase(int height, int width){

    for(int i = 0; i < coordinates.size(); i++){
        for(int c = 0; c < coordinates.at(i).size(); c++){

            if(coordinates.at(i).at(c) == 1){ // opening to the right
                if (c + 1 > width){
                    std::cout << "not possible";
                }else{    
                    return "0";
                }
                
            }else if(coordinates.at(i).at(c) == 2){ // opening to the left
                if (c - 1 < width){
                    std::cout << "not possible";
                }else{
                    return "0";
                }

            }else if(coordinates.at(i).at(c) == 3){ // opening to the bottom
                if (i + 1 > height){
                    std::cout << "not possible";
                }else{
                    return "0";
                }

            }else if(coordinates.at(i).at(c) == 4){ // opening to the top
                if (i + 1 < height){
                    std::cout << "not possible";
                }else{
                    return "0";
                }
            }
        }
    }
    return "0";
}

std::string print(std::vector<std::string> currentMase){
    for(int i = 0; i < currentMase.size(); i++){
        std::cout << currentMase.at(i) << "\n";
    }
    return "o";
}

int main(int argc, char **argv){
    int height, width, seed;
    maseGen maseGen;

    height = atoi (argv[1]);
    width = atoi (argv[2]);

    std::vector<std::string> currentMase(height, "");

    maseGen.createMase(height, width, currentMase);
    print(currentMase);

    return 0;
}