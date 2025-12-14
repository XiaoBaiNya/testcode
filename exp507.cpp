#include <iostream>
int main() {
  std::cout << "请输入一个整数n（1-9）：";
  int n;
  std::cin >> n; // 行数
  if (n <= 0 || n >= 10) {
    std::cout << "输入的数不在1-9以内";
    return -1;
  }
  int all = 0, jall = 0;
  for (int i = 1; i <= n; i++) {
    // 进入大循环
    // 子循环一
    int space_num = (n - i) * 2;
    for (; space_num > 0; space_num--) {
      std::cout << " ";
    }
    // 循环打印空格
    // 子循环二
    for (int num1 = 1; num1 < i; num1++) {
      std::cout << num1 << " ";
      all += num1;
      if (num1 % 2 != 0) {
        jall++;
      }
    }
    for (int num2 = i; num2 > 0; num2--) {
      std::cout << num2 << " ";
      all += num2;
      if (num2 % 2 != 0) {
        jall++;
      }
    }
    std::cout << std::endl;
    // 打印数字
  }
  std::cout << "金字塔数字总和：" << all << std::endl
            << "奇数个数：" << jall << std::endl;
}
