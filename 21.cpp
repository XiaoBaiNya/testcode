#include <iostream>
int p1[21], p2[21];
int p1_num = 2, p2_num = 2;
int p1_all, p2_all;
int rand_pai() { return rand() % 10 + 1; }
void chou(int x) {
  int *c_p = NULL;
  int *num_p = NULL;
  int *all_p = NULL;
  if (x == 1) {
    c_p = p1 + 2;
    num_p = &p1_num;
    all_p = &p1_all;
  } else {
    c_p = p2 + 2;
    num_p = &p2_num;
    all_p = &p2_all;
  }
  while (true) {
    if (*c_p != 0) {
      c_p += 1;
    } else {
      *c_p = rand_pai();
      *num_p += 1;
      *all_p += *c_p;
      break;
    }
  }
}
void p2_rand(int x) {
  if (p1_all >= p2_all) {
    int r = rand() % 10 + 1;
    if (r < x) {
      chou(2);
      std::cout << "对方抽了一张牌" << std::endl
                << "现在对方有" << p2_num << "张牌" << std::endl
                << std::endl;
    } else {
      std::cout << "对方不要牌" << std::endl
                << "现在对方有" << p2_num << "张牌" << std::endl
                << std::endl;
    }
  } else {
    std::cout << "对方不要牌" << std::endl
              << "现在对方有" << p2_num << "张牌" << std::endl
              << std::endl;
  }
}
void p2_action() {
  if (p2_all < 12) {
    chou(2);
    std::cout << "对方抽了一张牌" << std::endl
              << "现在对方有" << p2_num << "张牌" << std::endl
              << std::endl;
  } else if (p2_all < 15) {
    p2_rand(8); // p2=12 13 14 p2<p1 70抽30不抽
  } else if (p2_all < 17) {
    p2_rand(4); // p2=15 16   p2<p1 30抽70不抽
  } else if (p2_all < 19) {
    p2_rand(2); // p2=17 18 p2<p1 10抽90不抽
  } else {
    p2_rand(1); // p2=19 20 21 p2<p1 不抽
  }
}
bool p1_action() {
  std::cout << "你当前有" << p1_num << "张牌,点数一共是" << p1_all << std::endl
            << "要抽牌吗？（1.抽 2.不抽）" << std::endl
            << "：";
  int x;
  bool stop = true;
  std::cin >> x;
  switch (x) {
  case 1:
    chou(1);
    std::cout << "你现在有" << p1_num << "张牌,点数一共是" << p1_all
              << std::endl
              << std::endl;
    stop = false;
    break;
  case 2:
    break;
  }
  return stop;
}
bool is_check_false() { return (p1_all > 21 || p2_all > 21) ? true : false; }
int main() {
  std::srand(time(0));
  int money, earn_money = 0;
  std::cout << "输入你的金额（元）：";
  std::cin >> money;
  std::cout << "如果对方爆牌了，就会赢双倍的钱！！！" << std::endl;
  std::cout << "输入赌注的金额（元）：";
  std::cin >> earn_money;
  while (true) {
    bool keep = true;
    for (int i = 0; i <= 21; i++) {
      p1[i] = 0;
      p2[i] = 0;
    }
    for (int num = 0; num <= 1; num++) {
      p1[num] = rand_pai();
      p2[num] = rand_pai();
    }
    p1_num = 2, p2_num = 2;
    p2_all = p2[0] + p2[1];
    p1_all = p1[0] + p1[1];

    std::cout << "游戏开始！！！" << std::endl;
    while (keep) {
      std::cout << std::endl << "对方的回合！" << std::endl;
      p2_action();
      if (is_check_false()) {
        if (p1_all > 21) {
          std::cout << "你的点数为：" << p1_all << " 爆牌啦！" << std::endl
                    << "你输了" << earn_money * 2 << "元";
          money -= earn_money * 2;
          break;
        } else if (p2_all > 21) {
          std::cout << "对方的点数为：" << p2_all << " 爆牌啦！" << std::endl
                    << "你赢了" << earn_money * 2 << "元,双倍金钱！！！";
          money += earn_money * 2;
          break;
        }
      }
      std::cout << "现在是你的回合！" << std::endl;
      if (p1_action()) {
        if (p1_all > p2_all) {
          std::cout << "你的点数为：" << p1_all << std::endl
                    << "对方的点数为：" << p2_all << std::endl
                    << "你赢了" << earn_money << "元！";
          money += earn_money;
          break;
        } else if (p1_all < p2_all) {
          std::cout << "你的点数为：" << p1_all << std::endl
                    << "对方的点数为：" << p2_all << std::endl
                    << "你输了" << earn_money << "元";
          money -= earn_money;
          break;
        } else {
          std::cout << "你的点数和对方的点数都为：" << p1_all << std::endl;
          std::cout << "双赢啦~（不给钱）";
          break;
        }
      }
      if (is_check_false()) {
        if (p1_all > 21) {
          std::cout << "你的点数为：" << p1_all << " 爆牌啦！" << std::endl
                    << "你输了" << earn_money * 2 << "元";
          money -= earn_money * 2;
          break;
        } else if (p2_all > 21) {
          std::cout << "对方的点数为：" << p2_all << " 爆牌啦！" << std::endl
                    << "你赢了" << earn_money * 2 << "元,双倍金钱！！！";
          money += earn_money * 2;
          break;
        }
      }
    }
    std::cout << std::endl
              << std::endl
              << "你当前的金额为：" << money << std::endl
              << "还要继续玩吗？（0.不玩了 1.继续）" << std::endl
              << "：";
    std::cin >> keep;
    bool change = true;
    if (keep) {
      std::cout << "是否压大/缩小赌注？（0.是 1.否）";
      std::cin >> change;
    } else {
      break;
    }
    if (!change) {
      std::cout << "输入修改后的赌注金额：";
      std::cin >> earn_money;
    }
  }
}
