#include <cmath>
#include <iostream>
// 求一元二次方程
int main() {
  float a, b, c, x1, x2, x;
  std::cin >> a >> b >> c;
  if (a == 0 && b != 0) {
    x = -c / b;
    std::cout << x;
  } else if (a != 0) {
    if (b * b >= 4 * a * c) {
      x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
      x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
      std::cout << "x1=" << x1 << std::endl;
      std::cout << "x2=" << x2 << std::endl;
    } else {
      std::cout << "error";
    }
  } else {
    std::cout << "error";
  }
}
