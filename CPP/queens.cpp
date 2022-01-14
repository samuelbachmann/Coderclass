#include <iostream>
#include <vector>

int inputCheck(){
    int input;
    if(std::cin >> input){
        if(input == 2 or input <= 0){
            throw std::runtime_error("No solution found to place 2 queens on a 2 by 2 chess board");
        }else{return input;}
    }else{throw std::runtime_error("error: invalid input");}
}

bool checkPlacement(std::vector <std::vector<bool>> &board, int N, int row, int lane){
    row -= 1;
    if(row == 0){
        return true;
    }else if(lane -1 < N and lane + 1 > N){
        if(board.at(row).at(lane) and board.at(row).at(lane + 1) and board.at(row).at(lane - 1)){
            return true;
        }else{return false;}
    }else if(lane -1 < N){
        if(board.at(row).at(lane) and board.at(row).at(lane - 1)){
            return true;
    }else if(lane +1 < N){
        if(board.at(row).at(lane) and board.at(row).at(lane + 1)){
            return true;
        }
    }
}

bool placeQueens(int N, std::vector <std::vector<bool>> &board, int row){
    bool possible = true;
    int lane = 0;

    // while(possible == true){
    //     board.at(row).at(lane);
    //     if(checkPlacement(board, N, row, lane) == false){
    //         possible = false;
    //     }else{lane++;}
    // }

    if(row != N){
        // placeQueens(N, board, row++);
        return false;
    }else{return true;}
}

int main(){
    int amountQueens = 4;

    // std::cout << "How many queens to place on the board? ";
    // try{
    //     amountQueens = inputCheck();
    // }catch(std::runtime_error& excpt){
    //     std::cout << excpt.what() << std::endl;
    //     return 1;
    // }

    std::vector <bool> boardFalse(amountQueens, false);
    std::vector <std::vector<bool>> board(amountQueens, boardFalse);

    // placeQueens(amountQueens, board, 0);

    checkPlacement(board, amountQueens, 0, 0);
    return 0;
}