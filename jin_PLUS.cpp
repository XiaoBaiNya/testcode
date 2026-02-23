#include <iostream>
int main() {
  std::cout << "输入层数：";
  unsigned int a, b = 1;
  std::cin >> a;
  for (int i = 1; i <= a; i++) {
    for (int j = i; j < a; j++) {
      std::cout << " ";
    }
    for (int k = a - i; k < a; k++) {
      std::cout << "* ";
    }
    std::cout << std::endl;
  }
}
