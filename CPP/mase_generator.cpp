#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

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
        void createMase(int height, int width, std::vector<std::string>& currentMase);
        void maseGeneration(int seed, int height, int width, std::pair<int,int> cords, std::vector<std::string>& currentMase);
    private:
        std::vector<std::pair<int,int>> stack;
};

class cells{
    public: 
        std::pair<int,int> removeWallsCeilling(std::pair<int,int> cords, int what, int height, int width, std::vector<std::string>& currentMase);
    private:
};

void maseGen::createMase(int height, int width, std::vector<std::string>& currentMase){
    for(int i = 0; i < height; i++){
        if(i%2 != 0){
            for(int c = 0; c < width; c++){
                currentMase.at(i) += "|   ";
                if(c +1 == width){
                    currentMase.at(i) += "|";
                }
            }
        }else{
            for(int c = 0; c < width; c++){
                currentMase.at(i) += "+---";
                if(c +1 == width){
                    currentMase.at(i) += "+";
                }
            }
        }
    }
}

void maseGen::maseGeneration(int seed, int height, int width, std::pair<int,int> cords, std::vector<std::string>& currentMase){
    cells cells;
    std::pair<int,int> newCords;
    seed++;
    srand(seed);
    int randomWall = rand()%4;
    // stack.push_back(cords);

}

std::pair<int,int> cells::removeWallsCeilling(std::pair<int,int> cords, int what, int height, int width, std::vector<std::string>& currentMase){
    int x,y, newY, newX;
    x = cords.first * 2 + 1;
    y = cords.second * 4 + 2;
    newX = cords.first;
    newY = cords.second;

    if(what == 0){ //Opening to the right
        if(y + 1 > width){
            currentMase.at(x).at(y + 2) =' ';
            newY = cords.second + 1;
        }else{return std::make_pair(newX, newY);}
    }else if(what == 1){//Opening to the left
        if(y - 1 < 0){
            currentMase.at(x).at(y - 2) =' ';
            newY = cords.second - 1;
        }else{return std::make_pair(newX, newY);}
    }else if(what == 2){//Opening to the bottom
        if(x - 1 >! width){
            for(int i = 0; i < 3; i++){
                currentMase.at(x + 1).at(y - 1 + i) =' ';
            }
            newX = cords.first + 1;
        }else{return std::make_pair(newX, newY);}
    }else if(what == 3){//Opening to the top
        if(x - 1 < 0){
            for(int i = 0; i < 3; i++){
                currentMase.at(x - 1).at(y - 1 + i) =' ';
            }
            newX = cords.first - 1;
        }else{return std::make_pair(newX, newY);}
    }
    return std::make_pair(newX, newY);
}

void print(std::vector<std::string> currentMase){
    for(int i = 0; i < currentMase.size(); i++){
        std::cout << currentMase.at(i) << "\n";
    }
}

int main(int argc, char **argv){
    int height, width, seed;

    maseGen maseGen;
    cells cells;

    height = atoi (argv[1]) ;
    width = atoi (argv[2]);
    std::pair<int,int> cords(0,0);
    
    height = height * 2 + 1;
    std::vector<std::string> currentMase(height);

    if(argc == 4){
        seed = atoi (argv[3]);
    }else{seed = time(NULL);}

    maseGen.createMase(height, width, currentMase);
    cells.removeWallsCeilling(cords, 3, height, width, currentMase);
    print(currentMase);

    return 0;
}