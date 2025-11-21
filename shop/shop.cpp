#include "menu.cpp"
#include <iostream>
// NOTE: menu.cpp include choose_function and menu number
// data.cpp include goods

int main() {
  std::cout << "欢迎来到我的商店，想要什么？" << std::endl;
  for (int i = 0; i < std::size(menu); i++) {
    std::cout << i + 1 << "." << menu[i].name << std::endl;
  }

  int n, num;
  float price;
  std::cout << "：";
  std::cin >> n;
  switch (n) {
  case 1:
    price = choose_daily();
    break;
  case 2:
    price = choose_school();
    break;
  case 3:
    price = choose_eat();
    break;
  default:
    std::cout << "zakozako!~error!" << std::endl;
    return -1;
    break;
  }
  if (price == -1) {
    return -1;
  }
  std::cout << "要多少？" << std::endl << "：";
  std::cin >> num;
  if (std::cin.fail() || num <= 0) {
    std::cout << "zakozako!~error!" << std::endl;
    return -1;
  }
  std::cout << "一共:" << price * num << "元" << std::endl;
}
