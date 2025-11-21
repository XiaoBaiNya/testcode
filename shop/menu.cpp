#include "data.cpp"
#include <iostream>
#include <iterator>
struct One {
  std::string name;
};
One menu[]{{"日用品"}, {"文具"}, {"食品"}};

float choose_daily() {
  int num;
  for (int i = 0; i < std::size(daily); i++) {
    std::cout << i + 1 << "." << daily[i].name << " " << daily[i].price << "元 "
              << std::endl;
  }
  std::cout << "：";
  std::cin >> num;
  if (num <= 0 || num > std::size(daily)) {
    std::cout << "zakozako!~error!" << std::endl;
    return -1;
  }
  return daily[num - 1].price;
}

float choose_school() {
  int num;
  for (int i = 0; i < std::size(school); i++) {
    std::cout << i + 1 << "." << school[i].name << " " << school[i].price
              << "元 " << std::endl;
  }
  std::cout << "：";
  std::cin >> num;
  if (num <= 0 || num > std::size(school)) {
    std::cout << "zakozako!~error!" << std::endl;
    return -1;
  }
  return school[num - 1].price;
}

float choose_eat() {
  int num;
  for (int i = 0; i < std::size(eat); i++) {
    std::cout << i + 1 << "." << eat[i].name << " " << eat[i].price << "元 "
              << std::endl;
  }
  std::cout << "：";
  std::cin >> num;
  if (num <= 0 || num > std::size(eat)) {
    std::cout << "zakozako!~error!" << std::endl;
    return -1;
  }
  return eat[num - 1].price;
}
