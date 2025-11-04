#include <iostream>
int main() {
  int n, x = 1;
  for (std::cin >> n; x <= n; x++) {
    for (int y = 1; y <= x; y++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
}
