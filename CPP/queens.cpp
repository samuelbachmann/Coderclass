#include <iostream>
#include <vector>

int showBoard(std::vector<std::vector<std::string> > nQueens){
    for (int i = 0; i < nQueens.size(); i++) {
        for (int j = 0; j < nQueens[i].size(); j++){
            std::cout << nQueens[i][j];
        }
        std::cout << "\n";
    }
    return 0;
}

bool checkPosition(std::vector<std::vector<std::string> > nQueens, int row, int column, int N){
    for (int i = 0; i < column; i++){
        if (nQueens[row][i] == "Q"){
            return false;
        }
    }

   for (int i=row, j=column; i>=0 && j>=0; i--, j--){ 
       if (nQueens[i][j] == "Q"){
           return false;
       }
   }

   for (int i=row, j=column; i>=0 && j<N; i--, j++){ 
       if (nQueens[i][j] == "Q"){
           return false;
       }
   }

    for (int i = 0; i < N; i++){ 
        if (nQueens[i][column] == "Q"){
            return false;
        }
    }
   return true;
}

bool solveNQueen(std::vector<std::vector<std::string> > nQueens, int N, int row){
    if(row >= N){
        showBoard(nQueens);
        return true;
    }
    for( int k = 0; k < N; k++){
        if (checkPosition(nQueens, row, k, N)){
            nQueens[row][k] = "Q";
            if (solveNQueen(nQueens, N, row + 1)){
                return true;
            }
         nQueens[row][k] = ".";
        }
    }
    return false;
}

bool makeBoard(int N){
    std::vector<std::vector<std::string> > nQueens;
    for (int i = 0; i < N; i++){
        std::vector<std::string> v1;
        for (int j = 0; j < N; j++){ 
            v1.emplace_back(".");
        }
        nQueens.push_back(v1);
    }
    if(!solveNQueen(nQueens, N, 0)) {
      std::cout << "No solution found to place " << N << " queens on a " << N << " by " << N << " chess board";
      return false;
   }
   
   return true;

}


int readLine(){

    int N = 2;
    std::cout << "How many queens to place on the board? \n";

    if (std::cin >> N && N > 0){
        makeBoard(N);

    }else{
        throw std::runtime_error("invalid input");
    }

    return 0;
}


int main(){   
    try{
        readLine();
    }
    catch(std::runtime_error& excpt)
     {
         std::cout << "\nerror: " << excpt.what();
     }
    return 0;
}