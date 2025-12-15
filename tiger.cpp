#include <iomanip>
#include <iostream>
#include <string>
#include <thread>
int play_num = 0, gain_score[100];
int money, earn_money;
std::string pt(int n) {
  if (n == 1) {
    return "西瓜";
  } else if (n == 2) {
    return "香蕉";
  } else if (n == 3) {
    return "苹果";
  } else if (n == 4) {
    return "葡萄";
  } else if (n == 5) {
    return "钻石";
  } else {
    return " ";
  }
}
void print_score(int num[3], int time, int c, int x) {
  if (x == 0) {
    for (int i = 0; i < c; i++) {
      int j = i % 5 + 1;
      std::string text1 = pt(j);
      std::cout << std::setw(12) << text1 << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(time)); // 25
    }
  } else if (x == 1) {
    for (int i = 0; i < c; i++) {
      int j = i % 5 + 1;
      std::string text2 = pt(j);
      std::cout << std::setw(12) << pt(num[0]) << std::setw(12) << text2
                << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(time));
    }

  } else if (x == 2) {
    for (int i = 0; i < c; i++) {
      int j = i % 5 + 1;
      std::string text3 = pt(j);
      std::cout << std::setw(12) << pt(num[0]) << std::setw(12) << pt(num[1])
                << std::setw(12) << text3 << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(time));
    }
  } else {
    std::cout << std::setw(12) << pt(num[0]) << std::setw(12) << pt(num[1])
              << std::setw(12) << pt(num[2]) << std::endl;
  }
}
int score(int money, int num[3]) {
  if (num[0] == num[1] && num[1] == num[2]) { // 三连
    if (num[0] == 5) {                        // 钻石
      return 5 * money;
    } else { // 非钻石
      return 3 * money;
    }
  } else if (num[0] == num[1] || num[1] == num[2] || num[0] == num[2]) { // 二连
    if (((num[0] == num[1] || num[0] == num[2]) && num[0] == 5) ||
        (num[1] == num[2] && num[1] == 5)) { // 两个钻石
      return money * 2;
    } else {
      return money / 2;
    }
  } else { // 无
    return 0;
  }
}
void game_start() {
  std::cout << "请输入赌注的金额（元）：";
  std::cin >> earn_money;
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "游戏即将开始！" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << 3 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << 2 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << 1 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    int num[3];
    for (int i = 0; i <= 2; i++) {
      num[i] = rand() % 5 + 1;
    }
    print_score(num, 25, 60, 0);
    print_score(num, 25, 80, 1);
    print_score(num, 25, 50, 2);
    print_score(num, 50, 25, 2);
    print_score(num, 100, 15, 2);
    print_score(num, 200, 8, 2);
    print_score(num, 500, 2, 2);
    print_score(num, 25, 100, 3);
    money = money - earn_money + score(earn_money, num);
    if (earn_money > score(earn_money, num)) {
      std::cout << "你输了" << earn_money - score(earn_money, num) << "元"
                << std::endl;
      gain_score[play_num] = score(earn_money, num) - earn_money;
    } else if (earn_money < score(earn_money, num)) {
      std::cout << "你赢了" << score(earn_money, num) - earn_money << "元！！！"
                << std::endl;
      gain_score[play_num] = score(earn_money, num) - earn_money;
    }
    std::cout<<"当前余额"<<money<<"元"<<std::endl;
    play_num++;
    bool keep;
    std::cout << "还要继续玩吗？（1.是 0.否）：";
    std::cin >> keep;
    if (keep) {
      std::cout << "是否更改赌注？（1.是 0.否）【您当前赌注为" << earn_money
                << "元】：";
      bool change;
      std::cin >> change;
      if (change) {
        std::cout << "输入修改后的赌注：";
        std::cin >> earn_money;
      } else {
        continue;
      }
    } else {
      break;
    }
  }
}
void game_history() {
  std::cout<<"当前余额"<<money<<"元"<<std::endl;
  std::cout << "你一共玩了" << play_num << "把" << std::endl;
  int *p = gain_score;
  int f = 1;
  while (true) {
    if (*p == 0) {
      break;
    } else if (*p > 0) {
      std::cout << "第" << f << "把你赢了" << *p << "元" << std::endl;
      f++;
      p++;
    } else if (*p < 0) {
      std::cout << "第" << f << "把你输了" << -(*p) << "元" << std::endl;
      f++;
      p++;
    }
  }
}
int main() {
  srand(time(0));
  std::cout << "输入你的金额（元）：";
  std::cin >> money;
  std::cout
      << "如果有两个相同的物品（非钻石） "
         "玩家会获得一半的赌注（两个钻石直接获得两倍赌注金额！）"
      << std::endl
      << "如果有三个相同的物品（非钻石） "
         "玩家就会获得三倍赌注金额！！！（三个钻石直接获得五倍赌注金额！！！）"
      << std::endl;
  bool k = true;
  while (k) {
    std::cout << "1.立即开玩 2.查看历史记录 3.退出（会删除历史记录） ：";
    int n;
    std::cin >> n;
    switch (n) {
    case 1:
      game_start();
      break;
    case 2:
      game_history();
      break;
    case 3:
      k = false;
      break;
    }
  }
}

