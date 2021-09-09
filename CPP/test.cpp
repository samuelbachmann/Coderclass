#include <iostream>
#include <cmath>
int main () {
  int width;
  int length;
  int perimeter;
  int area;
  double diagonal;
  std::cout << "Please enter the length and width of the rectangle: " << std::endl;  
  std::cin >> width;
  std::cin >> length;
  perimeter = (width + length) * 2;
  std::cout << "perimeter: " << perimeter << std::endl;
  area = width * length;
  std::cout << "area: " << area << std::endl;
  diagonal = sqrt((width * width)+(length * length));
  std::cout << "diagonal: " << diagonal << std::endl;
}