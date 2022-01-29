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

class mazeGen{
    public:
        void createmaze(int height, int width, std::vector<std::string>& currentmaze);
        void mazeGeneration(int seed, int height, int width, std::pair<int,int> cords, std::vector<std::string>& currentmaze);
        bool checkIfvisited(int first, int second);
        std::pair<int,int> backtracking();
    private:
        std::vector<std::pair<int,int>> stack;
        std::vector<std::pair<int,int>> visited;

};

class cells{
    public: 
        std::pair<int,int> removeWallsCeilling(std::pair<int,int> cords, int what, int height, int width, std::vector<std::string>& currentmaze);
    private:
};

void mazeGen::createmaze(int height, int width, std::vector<std::string>& currentmaze){
    for(int i = 0; i < height; i++){
        if(i%2 != 0){
            for(int c = 0; c < width; c++){
                currentmaze.at(i) += "|   ";
                if(c +1 == width){
                    currentmaze.at(i) += "|";
                }
            }
        }else{
            for(int c = 0; c < width; c++){
                currentmaze.at(i) += "+---";
                if(c +1 == width){
                    currentmaze.at(i) += "+";
                }
            }
        }
    }
    return;
}

void mazeGen::mazeGeneration(int seed, int height, int width, std::pair<int,int> cords, std::vector<std::string>& currentmaze){
    std::cout << "hallo \n";
    std::cout << visited.size() << "\n";
    std::cout << height * width << "\n";
    cells cells;
    int removeType;
    std::pair<int,int> newCords;
    if(visited.size() - 1 == height * width){
        return;
    }else{
        stack.push_back(cords);
        visited.push_back(cords);
        seed++;
        srand(seed);
        removeType = rand()% 4;
        std::cout << removeType << "\n";

        if(removeType == 0 and cords.second + 1 <= width){ //Opening to the right
            if(checkIfvisited(cords.first, cords.second + 1) == false){
                std::cout << "1";
                cells.removeWallsCeilling(cords, removeType, height, width, currentmaze);
                newCords = std::make_pair(cords.first, cords.second + 1);
                mazeGeneration(seed, height, width, newCords, currentmaze);
            }
        }else if(removeType == 1 and cords.second - 1 >= 0){ //Opening to the left
            if(checkIfvisited(cords.first, cords.second - 1) == false){
                std::cout << "2";
                cells.removeWallsCeilling(cords, removeType, height, width, currentmaze);
                newCords = std::make_pair(cords.first, cords.second - 1);
                mazeGeneration(seed, height, width, newCords, currentmaze);
            }
        }else if(removeType == 2 and cords.first + 1 <= height){ //Opening to the bottom
            if(checkIfvisited(cords.first + 1, cords.second) == false){
                std::cout << "3";
                cells.removeWallsCeilling(cords, removeType, height, width, currentmaze);
                newCords = std::make_pair(cords.first + 1, cords.second);
                mazeGeneration(seed, height, width, newCords, currentmaze);
            }
        }else if(removeType == 3 and cords.first - 1 >= 0){ //Opening to the top
            if(checkIfvisited(cords.first - 1, cords.second) == false){
                std::cout << "4";
                cells.removeWallsCeilling(cords, removeType, height, width, currentmaze);
                newCords = std::make_pair(cords.first - 1, cords.second);
                mazeGeneration(seed, height, width, newCords, currentmaze);
            }
        }else{
            if(cords.second + 1 <= width){ //Opening to the right
                if(checkIfvisited(cords.first, cords.second + 1) == false){
                    std::cout << "5";
                    cells.removeWallsCeilling(cords, 0, height, width, currentmaze);
                    newCords = std::make_pair(cords.first, cords.second + 1);
                    mazeGeneration(seed, height, width, newCords, currentmaze);
                }
            }else if(cords.second - 1 >= 0){ //Opening to the left
                if(checkIfvisited(cords.first, cords.second - 1) == false){
                    std::cout << "6";
                    cells.removeWallsCeilling(cords, 1, height, width, currentmaze);
                    newCords = std::make_pair(cords.first, cords.second - 1);
                    mazeGeneration(seed, height, width, newCords, currentmaze);
                }
            }else if(cords.first + 1 <= height){ //Opening to the bottom
                if(checkIfvisited(cords.first + 1, cords.second) == false){
                    std::cout << "7";
                    cells.removeWallsCeilling(cords, 2, height, width, currentmaze);
                    newCords = std::make_pair(cords.first + 1, cords.second);
                    mazeGeneration(seed, height, width, newCords, currentmaze);
                }
            }else if(cords.first - 1 >= 0){ //Opening to the top
                if(checkIfvisited(cords.first - 1, cords.second) == false){
                    std::cout << "8";
                    cells.removeWallsCeilling(cords, 3, height, width, currentmaze);
                    newCords = std::make_pair(cords.first - 1, cords.second);
                    mazeGeneration(seed, height, width, newCords, currentmaze);
                }
            }
        }
    }
}

bool mazeGen::checkIfvisited(int first, int second){
    std::cout << first << "\n";
    std::cout << second << "\n";
    for(int i = 0; i < visited.size(); i++){
        if(first == visited.at(i).first and second == visited.at(i).second){
            return false;
        }else{
            return true;
        }
    }
    return false;
}

std::pair<int,int> mazeGen::backtracking(){
    std::pair<int,int> newCords;
    stack.pop_back();
    int length = stack.size();
    std::cout << length;
    newCords = stack.at(length);

    return std::make_pair(newCords.first, newCords.second);
}

std::pair<int,int> cells::removeWallsCeilling(std::pair<int,int> cords, int what, int height, int width, std::vector<std::string>& currentmaze){
    int x, y, newY, newX;
    x = cords.first * 2 + 1;
    y = cords.second * 4 + 2;
    newX = cords.first;
    newY = cords.second;

    if(what == 0){ //Opening to the right
        currentmaze.at(x).at(y + 2) =' ';
        newY = cords.second + 1;
    }else if(what == 1){//Opening to the left
        currentmaze.at(x).at(y - 2) =' ';
        newY = cords.second - 1;
    }else if(what == 2){//Opening to the bottom
        for(int i = 0; i < 3; i++){
            currentmaze.at(x + 1).at(y - 1 + i) =' ';
        }
        newX = cords.first + 1;
    }else if(what == 3){//Opening to the top
        for(int i = 0; i < 3; i++){
            currentmaze.at(x - 1).at(y - 1 + i) =' ';
        }
        newX = cords.first - 1;
    }
    return std::make_pair(newX, newY);
}

void print(std::vector<std::string> currentmaze){
    for(int i = 0; i < currentmaze.size(); i++){
        std::cout << currentmaze.at(i) << "\n";
    }
    return;
}

int main(int argc, char **argv){
    int height, width, seed;

    mazeGen mazeGen;
    cells cells;

    height = atoi (argv[1]) ;
    width = atoi (argv[2]);
    std::pair<int,int> cords(0,0);
    
    height = height * 2 + 1;
    std::vector<std::string> currentmaze(height);

    if(argc == 4){
        seed = atoi (argv[3]);
    }else{seed = time(NULL);}

    mazeGen.createmaze(height, width, currentmaze);
    mazeGen.mazeGeneration(seed, height, width, cords, currentmaze);
    print(currentmaze);

    return 0;
}