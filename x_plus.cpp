#include <iostream>

int main() {
  for (int a = 1; a <= 9; a++) {
    for (int b = 1; b <= a; b++) {
      std::cout << b << "*" << a << "=" << a * b << " ";
    }
    std::cout << std::endl;
  }
}
