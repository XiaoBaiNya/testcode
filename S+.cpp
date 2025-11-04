#include <iostream>
int main() {
  double x;
  std::cin >> x;
  double ds = 0.5 * x, d12 = 1 + 0.5 * x, n = 1.0;
  while (ds > 1e-6) {
    ds *= (0.5 - n) * x / (n + 1);
    d12 += ds;
    n++;
  }
  std::cout << d12 << std::endl;
}
