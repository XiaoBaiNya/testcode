#include <cmath>
#include <iostream>
// 求一元二次方程
int main() {
  float a, b, c, x1, x2;
  std::cin >> a >> b >> c;
  if (b * b >= 4 * a * c) {
    x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    std::cout << "x1=" << x1;
    std::cout << "x2=" << x2;
  } else {
    return 0;
  }
}
