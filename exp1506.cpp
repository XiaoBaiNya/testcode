#include <fstream>
#include <iostream>
#include <string>
/**
 * @class stu
 * @brief 链表保存name，成绩（A-E），平均成绩
 */
struct stu {
  std::string name;
  char score;
  double average_score;
  stu *next;
};
double calculateAverage(double a, double b) { return (a + b) / 2; }
double calculateAverage(double a, double b, double c) {
  return (a + b + c) / 3;
}
char getGradeLevel(double av) {
  if (av >= 90) {
    return 'A';
  } else if (av >= 80) {
    return 'B';
  } else if (av >= 70) {
    return 'C';
  } else if (av >= 60) {
    return 'D';
  } else {
    return 'E';
  }
}
bool isValidScore(double score) {
  return (score >= 0 && score <= 100) ? true : false;
}
/**
 * @brief  初始化链表，再进行输入操作，写入成绩同时计算及格优秀
 * @return 返回链表首指针，便于后续利用查询数据和扩展
 */
stu *inputStudentInfo() {
  std::cout << std::endl << "===输入学生信息===" << std::endl;
  int StudentNum;
student_num_check:
  std::cout << "学生数量：";
  std::cin >> StudentNum;
  if (StudentNum <= 0) {
    std::cout << "学生人数至少为1" << std::endl << "请重新输入";
    goto student_num_check;
  }
  stu *first = new stu{};
  stu *p = first;
  for (int i = 1; i < StudentNum; i++) {
    stu *new_stu = new stu{};
    p->next = new_stu;
    p = new_stu;
  }
  p = first;
  for (int i = 1; i <= StudentNum; i++) {
    printf("请输入第%d个学生信息：\n", i);
    std::cout << "姓名：";
    std::cin >> p->name;
    int n;
  class_num_check:
    std::cout << "课程数量（2或3）：";
    std::cin >> n;
    if (!(n == 2 || n == 3)) {
      std::cout << "非法课程数量，请重新输入";
      goto class_num_check;
    }
    double score[3] = {-1, -1, -1};
    for (int j = 1; j <= n; j++) {
    score_check:
      printf("成绩%d：", j);
      std::cin >> score[j - 1];
      if (!isValidScore(score[j - 1])) {
        std::cout << "非法成绩，请重新输入";
        goto score_check;
      }
    }
    if (n == 2) {
      p->average_score = calculateAverage(score[0], score[1]);
      p->score = getGradeLevel(p->average_score);
    } else {
      p->average_score = calculateAverage(score[0], score[1], score[2]);
      p->score = getGradeLevel(p->average_score);
    }
    p = p->next;
  }
  return first;
}
/**
 * @brief 删除所有链表，新建next到下一个新节点，再删除上一个节点，head跳转到next
 *
 * @param head 链表头
 */
void deletelist(stu *head) {
  while (head != nullptr) {
    stu *next = head->next;
    delete head;
    head = next;
  }
}
/**
 * @brief 输出链表内容
 *
 * @param head 链表头指针
 */
void analyzeStudent(stu *head) {
  int totalStudent = 0, excellentCount = 0, passCount = 0;
  std::cout << std::endl << "===成绩分析结果===" << std::endl;
  stu *p = head;
  while (p != nullptr) {
    std::cout << "学生：" << p->name << "，平均分：" << p->average_score
              << "，等级：" << p->score << std::endl;
    ++totalStudent;
    if (p->score <= 'D' && p->score > 'A') {
      ++passCount;
    } else if (p->score == 'A') {
      ++passCount;
      ++excellentCount;
    }
    p = p->next;
  }
  std::cout << std::endl << "===统计信息===" << std::endl;
  std::cout << "总学生数：" << totalStudent << std::endl;
  std::cout << "优秀学生数：" << excellentCount << std::endl;
  std::cout << "及格学生数：" << passCount << std::endl;
  std::cout << "不及格学生数：" << totalStudent - passCount << std::endl;
}
/**
 * @brief 链表内容保存到data.txt
 *
 * @param head 链表指针
 */
void savedata(stu *head) {
  std::cout << "是否保存？（y/n）：";
  char action = 'n';
  std::cin >> action;
  if (action == 'y' || action == 'Y') {
    stu *p = head;
    std::ofstream dataFile;
    dataFile.open("data.txt", std::ios::app | std::ios::out);
    while (dataFile && p != nullptr) {
      dataFile << p->name << " " << p->average_score << " " << p->score
               << std::endl;
      p = p->next;
    }
    dataFile.close();
  }
}
/**
 * @brief 读取data.txt里的内容到链表里
 *
 * @return 返回读取后的指针
 */
stu *getdataFile() {
  std::ifstream opendata;
  opendata.open("data.txt");
  stu *first = new stu{};
  stu *p = first;
  if (!(opendata >> first->name >> first->average_score >> first->score)) {
    delete first;
    return nullptr;
  }
  while (true) {
    stu *head = new stu{};
    if (!(opendata >> head->name >> head->average_score >> head->score)) {
      delete head;
      break;
    }
    p->next = head;
    p = head;
  }
  opendata.close();
  return first;
}
/**
 * @brief 删除data.txt里的文件
 */
void deltedatafile() {
  char action;
  std::cout << "确认删除吗？（y/n）：";
  std::cin >> action;
  if (action == 'y' || action == 'Y') {
    std::ofstream cleandata;
    cleandata.open("data.txt", std::ios::out);
    cleandata << "";
    cleandata.close();
    std::cout << "删除完毕！" << std::endl;
  }
}
int main() {
  int n;
  std::cout << "===学生成绩管理系统===（输入0查询指令）" << std::endl;
  while (true) {
    std::cout << "操作：";
    std::cin >> n;
    if (n == 1) {
      stu *head = getdataFile();
      analyzeStudent(head);
      deletelist(head);
    } else if (n == 2) {
      stu *head = inputStudentInfo();
      savedata(head);
      deletelist(head);
    } else if (n == 3) {
      deltedatafile();
    } else if (n == 0) {
      std::cout << "1.分析已有成绩 2.增加学生信息 3.删除所有信息 4.退出"
                << std::endl;
    } else {
      break;
    }
  }
}
