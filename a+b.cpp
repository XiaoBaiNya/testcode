#include <iostream>
using std::cin;
using std::cout;
// a+b PLUS
int main() {
  double a, b;
  cout << "本程序是用来计算a+b的结果的\n";
  cout << "请输入a：";
  cin >> a;
  if (cin.fail()) {
    cout << "输入的a不是数字！\n";
    return 0;
  }
  cout << "请输入b：";
  cin >> b;
  if (cin.fail()) {
    cout << "输入的b不是数字！\n";
    return 0;
  }
  cout << a << "+" << b << "=" << a + b << std::endl;
}
