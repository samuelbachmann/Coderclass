#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

// one block is 3x5 
//  +---+
//  |   |
//  +---+

class maseGeneration{
    public:
        std::string generateFilledMase(int length, int width);
    private:
        std::vector<std::vector<std::vector<std::string>>> mase;
        // vector 2D vector is the legnth 3D vector = width
};

std::string maseGeneration::generateFilledMase(int length, int width){
    
}

std::string printMase(){

}

int main(int argc, char **argv){
    int lenght, width, seed;

    lenght = atoi (argv[1]);
    width = atoi (argv[2]);

    return 0;
} 