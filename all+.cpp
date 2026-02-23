#include <iostream>
int main() {
  std::string text;
  std::cin >> text;
  int num = 0;
  for (char i : text) {
    num += i;
  }
  std::cout << num;
}
