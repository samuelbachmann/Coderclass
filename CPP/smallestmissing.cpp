#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  std::string numberInput;
  std::vector<int> numbersVector;
  float howManyNumbers, number, checkingNumber;

  std::cout << "How many numbers? ";
  std::cin >> howManyNumbers;
  std::cout << "Please enter the numbers: ";

  for(int i = 0 ; i < howManyNumbers; i++){
    std::cin >> number;
    numbersVector.push_back(number);
  }
  
  sort(numbersVector.begin(), numbersVector.end());

  checkingNumber = numbersVector[0];  zc
  checkingNumber = checkingNumber + 1;
  if(checkingNumber notin numbersVector){
    std::cout << "done";
  }
    return 0;
}