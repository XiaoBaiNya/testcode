#include <iostream>
using std::cin;
using std::cout;
// 三个数求最大值
int main() {
  int a, b, c, max;
  cin >> a >> b >> c;
  max = a;
  if (max < b)
    max = b;
  if (max < c)
    max = c;
  cout << max;
}
