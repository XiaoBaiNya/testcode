#include <iostream>
#include <string>
void pt(int a) {
  if (a <= 0) {
    throw std::string("传入值a<=0");
  }
  for (int i = 1; i <= a; i++) {
    for (int j = i; j < a; j++) {
      std::cout << " ";
    }
    for (int k = a - i; k < a; k++) {
      std::cout << "* ";
    }
    std::cout << std::endl;
  }
}
int main() {
  std::cout << "输入层数：";
  int num;
  std::cin >> num;
  try {
    pt(num);
  } catch (const std::string &text) {
    std::cout << "ERROR：" << text << std::endl;
  }
}
