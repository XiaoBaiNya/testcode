#include <iostream>
int main() {
  std::string a;
  std::cin >> a;
  int b = a.size(), d = 0;
  while (b >= 1) {
    char c = a[b - 1];
    d += c;
    b--;
  }
  std::cout << d;
}
