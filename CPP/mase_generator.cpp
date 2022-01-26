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
        std::vector<std::vector<std::string>> mase();
    private:
            std::vector<std::vector<int>> coordinates{
            {1,2,3,1,3},
            {3,2,4,2,2},
            {1,1,1,1,3},
            {3,2,2,2,2},
            {1,1,1,1,3},
        };
};

std::vector<std::vector<std::string>> maseGen::mase(){
    for(int i = 0; i < coordinates.size(); i++){
        for(int c = 0; c < coordinates.at(i).size(); c++){
            if(coordinates.at(i).at(c) == 1){ // opening to the right


            }else if(coordinates.at(i).at(c) == 2){ // opening to the left

            }else if(coordinates.at(i).at(c) == 3){ // opening to the bottom

            }else if(coordinates.at(i).at(c) == 4){ // opening to the top

            }
        }
    }

}

class Cell{
    public:
        std::string filledwall(){    
            return "|   ";
        }
        std::string emptyWall(){    
            return "|   ";
        }
        std::string filledRoof(){
            return "+---+";
        }
        std::string emptyRoof(){
            return "+   +";
        }
    private:
};

std::string print(int length, int width){

}

int main(int argc, char **argv){
    int lenght, width, seed;

    lenght = atoi (argv[1]);
    width = atoi (argv[2]);
    std::cout << print(lenght, width);

    return 0;
} 

// std::string print(int length, int width){
//     for(int i = 0; i < length; i++){
//         for(int c = 0; c < width; c++){
//             std::cout << "+---";
//             if(c +1 == width){
//                 std::cout << "+\n";
//             }
//         }
//         for(int c = 0; c < width; c++){
//             std::cout << "|   ";
//             if(c +1 == width){
//                 std::cout << "|\n";
//             }
//         }
//     }

//     for(int c = 0; c < width; c++){
//         std::cout << "+---";
//         if(c +1 == width){
//             std::cout << "+\n";
//         }
//     }
//     return "\ncompleted\n";
// }