#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  std::vector<int> numbersVector;
  int howManyNumbers, number, checkingNumber, m = 1;

  std::cout << "How many numbers? " << "\n";
  std::cin >> howManyNumbers;
  std::cout << "Please enter the numbers " << "\n";

  for(int i = 0 ; i < howManyNumbers; i++){
    std::cin >> number;
    numbersVector.push_back(number);
  }

  sort(numbersVector.begin(), numbersVector.end());
  checkingNumber = numbersVector[0] +1;

  while(true){
    if(checkingNumber == numbersVector[m]){
       checkingNumber += 1;
       m+=1;
    }else if(checkingNumber != numbersVector[m]){
      std::cout << "The smallest missing number is " << checkingNumber << "\n";
      break;
    }
  }
    return 0;
}