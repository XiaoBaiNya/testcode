#include <iostream>
#include <limits>
int main() {
  int n, numn, max_n, cnumn = 0;
  std::cout << "主人~ 我可以帮您算出n个数里的最大值喵~" << std::endl
            << "告诉我您要几个数：";
  std::cin >> n;
  double max[n];
  if (std::cin.fail()) {
    std::cout << "杂鱼主人~ 你输入的n是整数喵？" << std::endl;
    return -1;
  } else if (n <= 1) {
    std::cout << "杂鱼主人~ n必须要大于1喵~" << std::endl;
    return -1;
  }
  numn = n;
  n--;
  max_n = n;
  n--;
  while (cnumn < numn) {
    std::cout << "输入第" << cnumn + 1 << "个数：";
    std::cin >> max[cnumn];
    if (std::cin.fail()) {
      std::cout << "杂鱼主人~ 你输入的是数字喵？给本喵重新输入！" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    cnumn++;
  }
  while (n > 0) {
    while (max[max_n] < max[n]) {
      max_n = n;
    }
    n--;
  }
  std::cout << "主人~ 您刚刚输入的" << numn << "个数里，最大的是" << max[max_n]
            << "喵~" << std::endl;
}
