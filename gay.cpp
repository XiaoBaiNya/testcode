#include <iostream>
#include <thread> // 必需头文件/
// NOTE:
// fuck是输入的字符串 a是fuck的长度 每次循环一首先string c，
// c是fuck的0到b的字符串 然后b++后 再循环 c就会长度+1 d是0
// 循环二获取fuck的b位字符 从0循环打印到该字符
int main() {
  std::string fuck;
  std::getline(std::cin, fuck);
  int a = fuck.size();
  int b = 0;
  while (a > b) { // 循环一
    std::string c = fuck.substr(0, b);
    char d = 33;
    while (d <= fuck[b]) { // 循环二
      std::cout << c << d << std::endl;
      d++;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    b++;
  }
}
