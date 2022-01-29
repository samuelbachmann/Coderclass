#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include <algorithm>

int main(){
  for(int seed = 6; seed < 36; seed++){
    srand(seed);
    int removeType = rand()% 4;

    std::cout << removeType;
  }

  return 0;
}