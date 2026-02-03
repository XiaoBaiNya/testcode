/**
 * @Author: XiaoBaiNya
 * @Created: 2026-01-31 17:07:27
 */

#include <fstream>
#include <iostream>
#include <string>
/**
 * @class stu
 * @brief 链表保存name，成绩（A-E），平均成绩
 */
struct stu {
  std::string name;
  std::string id;
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
  int totalStudent;
student_num_check:
  std::cout << "学生数量：";
  std::cin >> totalStudent;
  if (totalStudent <= 0) {
    std::cout << "学生人数至少为1" << std::endl << "请重新输入";
    goto student_num_check;
  }
  stu *first = new stu{};
  stu *p = first;
  for (int i = 1; i < totalStudent; i++) {
    stu *new_stu = new stu{};
    p->next = new_stu;
    p = new_stu;
  }
  p = first;
  for (int i = 1; i <= totalStudent; i++) {
    printf("请输入第%d个学生信息：\n", i);
    std::cout << "姓名：";
    std::cin >> p->name;
    std::cout << "学号：";
    std::cin >> p->id;
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
 * @brief 更改学生信息
 *
 * @param head 读取头指针
 * @return 是否修改
 */
bool change_student_information(stu *head) {
  std::cout << std::endl << "===更改学生信息===" << std::endl;
  bool is_tosave = false;
  if (head != nullptr) {
    stu *p;
    int num = 1;
    for (p = head; p != nullptr; p = p->next, num++) {
      std::cout << num << "： " << "姓名：" << p->name << "，学号：" << p->id
                << "，平均成绩：" << p->average_score << "，等级：" << p->score
                << std::endl;
    }
  invalid_num_check:
    std::cout << "要更改的序号：";
    int change_num;
    std::cin >> change_num;
    if (change_num <= 0 || change_num > num - 1) {
      std::cout << "非法序号，请重新输入";
      goto invalid_num_check;
    }
    int i;
    for (p = head, i = 1; i < change_num; i++, p = p->next)
      ;
    std::cout << "要更改信息如下：" << std::endl;
    std::cout << "姓名：" << p->name << "，学号：" << p->id << "，平均成绩："
              << p->average_score << "，等级：" << p->score << std::endl;
    char is_change = 'N';
    std::cout << "是否更改学生姓名（y/n）：";
    std::cin >> is_change;
    if (is_change == 'y' || is_change == 'Y') {
      is_tosave = true;
      std::cout << "输入更改后的姓名：";
      std::cin >> p->name;
    }
    is_change = 'N';
    std::cout << "是否更改学生学号（y/n）：";
    std::cin >> is_change;
    if (is_change == 'y' || is_change == 'Y') {
      is_tosave = true;
      std::cout << "输入更改后的学号：";
      std::cin >> p->id;
    }
    is_change = 'N';
    std::cout << "是否更改学生平均成绩（y/n）：";
    std::cin >> is_change;
    if (is_change == 'y' || is_change == 'Y') {
    change_score:
      std::cout << "输入更改后的成绩：";
      is_tosave = true;
      std::cin >> p->average_score;
      if (!isValidScore(p->average_score)) {
        std::cout << "非法成绩，请重新输入";
        goto change_score;
      }
      p->score = getGradeLevel(p->average_score);
    }
    if (is_tosave) {
      std::cout << "更改后学生信息如下：" << std::endl;
      std::cout << "姓名：" << p->name << "，学号：" << p->id << "，平均成绩："
                << p->average_score << "，等级：" << p->score << std::endl;
    }

  } else {
    std::cout << "暂无信息可修改" << std::endl;
  }
  return is_tosave;
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
 * @brief 输出链表内容 并且同时排序
 *
 * @param head 链表头指针
 */
void analyzeStudent(stu *head) {
  for (stu *p = head; p != nullptr; p = p->next) {
    stu *p2, *p_max = p;
    for (p2 = p; p2 != nullptr; p2 = p2->next) {
      if (p_max->average_score < p2->average_score) {
        p_max = p2;
      }
    }
    double t_average = p->average_score;
    std::string t_name = p->name;
    std::string t_id = p->id;
    char t_score = p->score;
    p->average_score = p_max->average_score;
    p->name = p_max->name;
    p->id = p_max->id;
    p->score = p_max->score;
    p_max->average_score = t_average;
    p_max->name = t_name;
    p_max->id = t_id;
    p_max->score = t_score;
  }
  int totalStudent = 0, excellentCount = 0, passCount = 0;
  std::cout << std::endl << "===成绩分析结果===" << std::endl;
  stu *p = head;
  while (p != nullptr) {
    std::cout << "姓名：" << p->name << "，学号：" << p->id << "，平均分："
              << p->average_score << "，等级：" << p->score << std::endl;
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
void savedata(stu *head, bool is_overwirte) {
  std::cout << "是否保存？（y/n）：";
  char action = 'n';
  std::cin >> action;
  if (action == 'y' || action == 'Y') {
    stu *p = head;
    std::ofstream dataFile;
    if (is_overwirte) {
      dataFile.open("data.txt", std::ios::out);
    } else {
      dataFile.open("data.txt", std::ios::app | std::ios::out);
    }
    while (dataFile && p != nullptr) {
      dataFile << p->name << " " << p->id << " " << p->average_score << " "
               << p->score << std::endl;
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
  if (!(opendata >> first->name >> first->id >> first->average_score >>
        first->score)) {
    delete first;
    return nullptr;
  }
  while (true) {
    stu *head = new stu{};
    if (!(opendata >> head->name >> head->id >> head->average_score >>
          head->score)) {
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
void deletedatafile() {
  char action;
  std::cout << "确认删除所有信息吗？（y/n）：";
  std::cin >> action;
  if (action == 'y' || action == 'Y') {
    std::ofstream cleandata;
    cleandata.open("data.txt", std::ios::out);
    cleandata << "";
    cleandata.close();
    std::cout << "删除完毕！" << std::endl;
  }
}
/**
 * @brief 删除一个学生信息
 *
 * @param head 链表头指针
 */
bool delete_one_information(stu *&head) {
  std::cout << std::endl << "===删除学生信息===" << std::endl;
  bool isdelete = true;
  if (head != nullptr) {
    stu *p;
    int num = 1;
    for (p = head; p != nullptr; p = p->next, num++) {
      std::cout << num << "： " << "姓名：" << p->name << "，学号：" << p->id
                << "，平均成绩：" << p->average_score << "，等级：" << p->score
                << std::endl;
    }
  invalid_num_check:
    std::cout << "要删除的序号：";
    int delete_num;
    std::cin >> delete_num;
    if (delete_num <= 0 || delete_num > num - 1) {
      std::cout << "非法序号，请重新输入";
      goto invalid_num_check;
    }
    if (delete_num == 1) {
      p = head->next;
      delete head;
      head = p;
    } else {
      p = head;
      int i;
      for (i = 1; i < delete_num; i++, p = p->next)
        ;
      if (p->next == nullptr) {
        stu *ddd = p;
        for (i = 1, p = head; i < delete_num - 1; i++, p = p->next)
          ;
        p->next = nullptr;
        delete ddd;
      } else {
        for (i = 1, p = head; i < delete_num - 1; i++, p = p->next)
          ;
        stu *next = ((p->next)->next);
        stu *ddd = p->next;
        p->next = next;
        delete ddd;
      }
    }
    std::cout << "删除后" << std::endl;
    for (p = head, num = 1; p != nullptr; p = p->next, num++) {
      std::cout << num << "： " << "姓名：" << p->name << "，学号：" << p->id
                << "，平均成绩：" << p->average_score << "，等级：" << p->score
                << std::endl;
    }
  } else {
    std::cout << "暂无信息可删除" << std::endl;
    isdelete = false;
  }
  return isdelete;
}
int main() {
  short n;
  std::cout << "===学生成绩管理系统===（输入0查询指令）" << std::endl;
  while (true) {
    std::cout << std::endl << "操作：";
    std::cin >> n;
    if (n == 1) {
      stu *head = getdataFile();
      analyzeStudent(head);
      deletelist(head);
    } else if (n == 2) {
      stu *head = inputStudentInfo();
      savedata(head, false);
      deletelist(head);
    } else if (n == 3) {
      stu *head = getdataFile();
      bool true_delete = delete_one_information(head);
      if (true_delete) {
        savedata(head, true);
      }
      deletelist(head);
    } else if (n == 4) {
      stu *head = getdataFile();
      bool true_chang = change_student_information(head);
      if (true_chang) {
        savedata(head, true);
      }
      deletelist(head);
    } else if (n == 5) {
      deletedatafile();
    } else if (n == 0) {
      std::cout << std::endl
                << "1.查询已有成绩 2.增加学生信息 3.删除学生信息 "
                   "4.更改学生信息 5.删除所有信息 6.退出"
                << std::endl;
    } else {
      break;
    }
  }
}
