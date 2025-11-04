#include <iostream>
// 乘法表
int main() {
  int a = 1, b = 1;
  while (a < 10) {
    while (b < 10) {
      std::cout << a << "×" << b << "=" << a * b << std::endl;
      b++;
    }
    a++;
    b = a;
  }
}
