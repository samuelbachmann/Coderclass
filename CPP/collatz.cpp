#include <iostream>

int getNewN(int n) {
  if (n % 2) {
      n = n*3+1;
  } else {
    n = n/2;
  }
  std::cout << n << ' ';
  return n;
}

int main() {
  int n;
  std::cout << "Enter the first number of the sequence: \n";
  std::cin >> n;
  std::cout << n << ' ';
  while (n > 1) {
    n = getNewN(n);
  }
  for (int i = 0; i < 6; i++) {
    n = getNewN(n);
  }

  std::cout << "...";
  return 0;
}