#include <iostream>
int sizeten(int ten, int toten) {
  int sten = 0;
  while (ten > 0) {
    ten /= toten;
    sten++;
  }
  return sten;
}
int main() {
  std::cout << "主人喵~我可以把10进制整数转换为2,"
               "8或16进制!"
            << std::endl
            << "告诉我您要转换的10进制喵~" << std::endl
            << "：";
  int ten, toten;
  std::cin >> ten;
  if (std::cin.fail()) {
    std::cout << "杂鱼主人喵~" << std::endl
              << "你输入的是10进制整数喵？不会连10进制都不知道是什么吧~（笑）"
              << std::endl;
    return -1;
  }
  std::cout << "您要把" << ten << "转化成2,8还是16进制喵？" << std::endl
            << "：";
  std::cin >> toten;
  if (toten == 2 || toten == 8 || toten == 16) {
    int a = sizeten(ten, toten);
    int TEN[a];
    int tenbak = ten, num = 0;
    while (num < a) {
      TEN[num] = tenbak % toten;
      tenbak /= toten;
      num++;
    }
    std::cout << "主人~我帮你转化好了喵！" << std::endl
              << ten << "的10进制转换为" << toten << "进制的结果为";
    while (a > 0) {
      int word = TEN[a - 1];
      if (word < 10)
        std::cout << word;
      else
        std::cout << static_cast<char>('A' + word - 10);
      a--;
    }
    std::cout << "喵~" << std::endl;
  } else if (toten == 10) {
    std::cout << "逗我玩喵？" << ten << "的10进制就是" << ten << "喵~"
              << std::endl;
  } else {
    std::cout << "杂鱼主人喵，打出2 or 8 or 16对你来说居然很难喵？"
              << std::endl;
  }
}
