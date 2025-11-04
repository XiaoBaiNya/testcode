#include <iostream>
void pt(int x, int y) {
  while (x - y > 0) {
    std::cout << " ";
    x--;
  }
  while (y > 0) {
    std::cout << "*" << " ";
    y--;
  }
}
int main() {
  std::cout << "输入层数：";
  unsigned int a, b = 1;
  std::cin >> a;
  if (std::cin.fail()) {
    std::cout << "你妈了个逼，输入的不是层数" << std::endl;
    return -1;
  } else if (a == 0) {
    std::cout << "骚货，我看你像骚0" << std::endl;
    return -1;
  }
  while (b <= a) {
    pt(a, b);
    std::cout << std::endl;
    b++;
  }
}
