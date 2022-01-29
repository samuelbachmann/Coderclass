#include <iostream>
#include <ctime>
#include <stack>
#include <vector>

class maze {
  public:
    maze();
    void mazeGen(int height, int width);
    int random(std::vector<int> celssAvailable);
    std::vector<int> cells(int height, int width);
    std::vector<int> cellsPathfinder();
    std::vector<std::vector<char>> backtracking(int height, int width);
    bool pathfinder();
    void print(int height, int width); 
    
  private:
    std::vector<std::vector<char>> Maze; 
    std::stack<std::pair<int, int>> stack;
    std::stack<std::pair<int, int>> visited;
    int right;
    int down;
    int left; 
    int up;
};
maze::maze(){
  stack.push({1,2});
  visited.push({1,2});
  right = 1;
  down = 2;
  left = 3;
  up = 4;
}
bool maze::pathfinder(){
  int y = visited.top().first;
  int x = visited.top().second;
  Maze.at(y).at(x) = '.';
  std::vector<int> CellsToGo = cellsPathfinder();
  if (Maze.at(y).at(x) == Maze.at(Maze.size()-3).at(Maze.at(0).size()-4)){
    return true;
    exit(EXIT_SUCCESS);
  }
  if (CellsToGo.size() == 0)
  {
    Maze.at(y).at(x) = '*';
    visited.pop();
    pathfinder();
  }
  for (size_t i = 0; i < CellsToGo.size(); i++)
  {
    if (CellsToGo[i] == right)
    {
      visited.push(std::make_pair(y, x+4));
      if (pathfinder())
        return true;
    }
    else if (CellsToGo[i] == down)
    {
      visited.push(std::make_pair(y+2, x));
      if (pathfinder())
        return true;
    }
    else if (CellsToGo[i] == left)
    {
      visited.push(std::make_pair(y, x-4));
      if (pathfinder())
        return true;
    }
    else if (CellsToGo[i] == up)
    {
      visited.push(std::make_pair(y-2, x));
      if (pathfinder())
        return true;
    }
    
  }
  return false;
}

int maze::random(std::vector<int> celssAvailable){
  int randNumber = (rand() % celssAvailable.size());
  return celssAvailable[randNumber];
}

void maze::mazeGen(int height, int width){
  std::vector < std::vector<char>> Maze((height*2+2), std::vector<char>(width*4+2));
  for (size_t i = 0; i < height*2+1; i++)
  {
    for (size_t c = 0; c < width*4+1; c++)
    {
      if (i % 2 == 1 and (c == 0 or c % 4 == 0))
        Maze.at(i).at(c) = '|';
      else if (c == 0 or c % 4 == 0)
        Maze.at(i).at(c) = '+';
      else if (i == 0 or i % 2 == 0)
        Maze.at(i).at(c) = '-';
      else if (c % 2 == 0 and i % 2 == 1)
        Maze.at(i).at(c) = '~';
      else
        Maze.at(i).at(c) = ' ';
      
    }
  }
  maze::Maze = Maze;
}

std::vector<std::vector<char>> maze::backtracking(int height, int width){
  int totalSquares = (height*width);
  int squaresPlaced = 0;
  maze::mazeGen(height, width);
  Maze.at(1).at(2) = ' ';
  while (totalSquares-1 > squaresPlaced)
  {
    std::vector<int> celssAvailable = maze::cells(height, width);
    if (celssAvailable.size() == 0){
      stack.pop();
    }
    else
    {
      int random = maze::random(celssAvailable);
      int y = maze::stack.top().first;
      int x = maze::stack.top().second;
      switch (random)
      {
      case 1:
        Maze.at(y).at(x+4) = ' ';
        Maze.at(y).at(x+2) = ' ';
        stack.push(std::make_pair(y, x+4));
        squaresPlaced++;
        break;
      case 2:
        Maze.at(y+2).at(x) = ' ';
        stack.push(std::make_pair(y+2, x));
        Maze.at(y+1).at(x-1) = ' ';
        Maze.at(y+1).at(x) = ' ';
        Maze.at(y+1).at(x+1) = ' ';
        squaresPlaced++;
        break;
      case 3:
        Maze.at(y).at(x-4) = ' ';
        Maze.at(y).at(x-2) = ' ';
        stack.push(std::make_pair(y, x-4));
        squaresPlaced++;
        break;
      case 4:
        Maze.at(y-2).at(x) = ' ';
        Maze.at(y-1).at(x-1) = ' ';
        Maze.at(y-1).at(x) = ' ';
        Maze.at(y-1).at(x+1) = ' ';
        stack.push(std::make_pair(y-2, x));
        squaresPlaced++;
        break;
      }
    }
  }
  maze::pathfinder();
  return Maze;
}

void maze::print(int height, int width){

  std::vector<std::vector<char>> Maze = maze::backtracking(height, width);

  for (int i = 0; i != height*2+1; i++) {
    Maze.at(i).pop_back();
    for (int c = 0; c != width*4+1; c++) {
      if (Maze.at(i).at(c) == '*')
        Maze.at(i).at(c) = ' ';
      std::cout <<Maze.at(i).at(c);
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
}

std::vector<int> maze::cellsPathfinder(){
  int y = visited.top().first;
  int x = visited.top().second;
  std::vector<int> CellsToGo;
  if (x+4 < Maze.at(0).size() and x+4 > 0 and maze::Maze.at(y).at(x+2) != '|' and Maze.at(y).at(x+4) != '.' and Maze.at(y).at(x+4) != '*')
    CellsToGo.push_back(1);
  else if (y+2 < Maze.size() and y+2 > 0 and maze::Maze.at(y+1).at(x) != '-' and Maze.at(y+2).at(x) != '.' and Maze.at(y+2).at(x) != '*')
    CellsToGo.push_back(2);
  else if (x-2 < Maze.at(0).size() and x-2 > 0 and maze::Maze.at(y).at(x-2) != '|' and Maze.at(y).at(x-4) != '.' and Maze.at(y).at(x-4) != '*')
    CellsToGo.push_back(3);
  else if (y-2 < Maze.size() and y-2 > 0 and maze::Maze.at(y-1).at(x) != '-' and Maze.at(y-2).at(x) != '.' and Maze.at(y-2).at(x) != '*')
    CellsToGo.push_back(4);
  return CellsToGo;
}

std::vector<int> maze::cells(int height, int width){
  int y = maze::stack.top().first;
  int x = maze::stack.top().second;
  std::vector<int> listOfCells;
  if (x+4 < 4*width+1 and x+4 > 0 and Maze.at(y).at(x+4) != ' ')
  {
    listOfCells.push_back(1);
  }
  if (y+2 < 2*height+1 and y+2 > 0 and Maze.at(y+2).at(x) != ' ')
  {
    listOfCells.push_back(2);
  }
  if (x-4 < 4*width+1 and x-4 > 0 and Maze.at(y).at(x-4) != ' ')
  {
    listOfCells.push_back(3);
  }
  if (y-2 < 2*height+1 and y-2 > 0 and Maze.at(y-2).at(x) != ' ')
  {
    listOfCells.push_back(4);
  }
  return listOfCells;
}



int main(int argc, char *argv[]){
  int height = 0, width = 0;
  srand(time(NULL));
  
  int randomSeed = 0;
  if (argc < 3){
    exit(EXIT_FAILURE);
  }
  else if (argc == 4)
  {
    height = atoi (argv[1]);
    width = atoi (argv[2]);
    randomSeed = atoi (argv[3]);
    srand(randomSeed);
  }
  else if (argc == 3)
  {
    height = atoi (argv[1]);
    width = atoi (argv[2]);
    srand(time(NULL));
  }

    maze maze;
    maze.print(height, width);
  
    return 0;
}