#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include <algorithm>

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
        bool checkIfvisited(std::pair<int,int> cords);
    private:
        std::vector<std::pair<int,int>> stack;
        std::vector<std::pair<int,int>> visited;

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
    return;
}

void maseGen::maseGeneration(int seed, int height, int width, std::pair<int,int> cords, std::vector<std::string>& currentMase){
    cells cells;
    int removeType;
    if(visited.size() - 1 == height * width){
        return;
    }else{
        stack.push_back(cords);
        visited.push_back(cords);
        seed++;
        srand(seed);
        removeType = rand()% 4;
        if(removeType == 0 and cords.second + 1 <= width){
            std::cout << "hallo 4 ";
            if(checkIfvisited(std::make_pair(cords.first, cords.second + 1)) == true){
                cells.removeWallsCeilling(cords, removeType, height, width, currentMase);
            }
        }else if(removeType == 1 and cords.second - 1 >= 0){
            std::cout << "hallo 3 ";
            if(checkIfvisited(std::make_pair(cords.first, cords.second - 1)) == true){
                cells.removeWallsCeilling(cords, removeType, height, width, currentMase);
            }
        }else if(removeType == 2 and cords.first + 1 <= height){
            std::cout << "hallo 2 ";
            if(checkIfvisited(std::make_pair(cords.first + 1, cords.second)) == true){
                cells.removeWallsCeilling(cords, removeType, height, width, currentMase);
            }
        }else if(removeType == 3 and cords.first - 1 >= 0){
            std::cout << "hallo 1 ";
            if(checkIfvisited(std::make_pair(cords.first - 1, cords.second)) == true){
                cells.removeWallsCeilling(cords, removeType, height, width, currentMase);
            }
        }else{
            
        }
    }
}

bool maseGen::checkIfvisited(std::pair<int,int> cords){
    for(int i = 0; i < visited.size(); i++){
        if(cords == visited.at(i)){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

std::pair<int,int> cells::removeWallsCeilling(std::pair<int,int> cords, int what, int height, int width, std::vector<std::string>& currentMase){
    int x,y, newY, newX;
    x = cords.first * 2 + 1;
    y = cords.second * 4 + 2;
    newX = cords.first;
    newY = cords.second;

    if(what == 0 /* and cords.second + 1 <= width */){ //Opening to the right
        currentMase.at(x).at(y + 2) =' ';
        newY = cords.second + 1;
    }else if(what == 1 /* and cords.second - 1 >= 0 */ ){//Opening to the left
        currentMase.at(x).at(y - 2) =' ';
        newY = cords.second - 1;
    }else if(what == 2 /* and cords.first + 1 <= height */){//Opening to the bottom
        for(int i = 0; i < 3; i++){
            currentMase.at(x + 1).at(y - 1 + i) =' ';
        }
        newX = cords.first + 1;
    }else if(what == 3 /* and cords.first - 1 >= 0 */){//Opening to the top
        for(int i = 0; i < 3; i++){
            currentMase.at(x - 1).at(y - 1 + i) =' ';
        }
        newX = cords.first - 1;
    }
    return std::make_pair(newX, newY);
}

void print(std::vector<std::string> currentMase){
    for(int i = 0; i < currentMase.size(); i++){
        std::cout << currentMase.at(i) << "\n";
    }
    return;
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
    // cells.removeWallsCeilling(cords, 3, height, width, currentMase);
    maseGen.maseGeneration(seed, height, width, cords, currentMase);
    print(currentMase);

    return 0;
}