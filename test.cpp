/**
 * @Author: XiaoBaiNya
 * @Created: 2026-04-16 14:24:52
 * @Encoding: utf-8
 * @Indent: 2 spaces
 */

#include <iostream>
namespace MyLib {
enum class Status {
  Yes,
  No,
  Success,
  Waring_Not_Found,
  Error_Invalid_Index,
  Error_Extra_Index,
  Error_Container_Empty,
};
using Data_Type = int;
class SeqList {
private:
  static constexpr int MAXSIZE = 100;
  Data_Type data[MAXSIZE] = {0};
  int num = 0;

public:
  SeqList(const int n = 0) : num(n) {
    if (n < 1 || n > MAXSIZE) {
      return;
    }
    for (int i = 0; i < n; i++) {
      std::cin >> data[i];
    }
  }
  Status IsEmpty() { return num == 0 ? Status::Yes : Status::No; }
  int Size() { return num; }
  Status Get_Data(const int target_index, Data_Type &get_data) {
    if (target_index <= 0) {
      get_data = 0;
      return Status::Error_Invalid_Index;
    } else if (num < target_index) {
      get_data = 0;
      return Status::Error_Extra_Index;
    } else {
      get_data = data[target_index - 1];
      return Status::Success;
    }
  }
  Status Search_data(const Data_Type target_data, int &get_index) {
    int i = 0;
    bool is_found = false;
    for (; i < num; i++) {
      if (target_data == data[i]) {
        is_found = true;
        break;
      }
    }
    get_index = is_found ? i + 1 : 0;
    return is_found ? Status::Success : Status::Waring_Not_Found;
  }
  Status Insert(const Data_Type new_data, const int target_index) {
    if (target_index < 1) {
      return Status::Error_Invalid_Index;
    } else if (num + 1 > MAXSIZE) {
      return Status::Error_Extra_Index;
    }
    for (int j = num; j >= target_index; j--) {
      data[j] = data[j - 1];
    }
    data[target_index - 1] = new_data;
    ++num;
    return Status::Success;
  }
  Status Delete(const int target_index) {
    if (num == 0) {
      return Status::Error_Container_Empty;
    } else if (target_index < 1) {
      return Status::Error_Invalid_Index;
    } else if (target_index > num) {
      return Status::Error_Extra_Index;
    }
    for (int j = target_index - 1; j < num; j++) {
      if (j + 1 == MAXSIZE) {
        break;
      }
      data[j] = data[j + 1];
    }
    --num;
    return Status::Success;
  }
  void print() {
    for (int i = 0; i < num; i++) {
      std::cout << data[i] << " ";
    }
  }
  void backprint() {
    for (int i = num - 1; i >= 0; i--) {
      std::cout << data[i] << " ";
    }
  }
  void Delete_same_data() {
    for (int i = 0; i < num; i++) {
      Data_Type p = data[i];
      int l = i + 1;
      for (int j = i + 1; j < num; j++) {
        if (p != data[j]) {
          data[l] = data[j];
          ++l;
        }
      }
      num = l;
    }
  }
  friend Status create_SeqList(const SeqList &A, const SeqList &B, SeqList &C) {
    if (A.num + B.num > MAXSIZE) {
      return Status::Error_Extra_Index;
    }
    int i = 0, a = 0, b = 0;
    for (; a < A.num && b < B.num; ++i) {
      if (A.data[a] < B.data[b]) {
        C.data[i] = A.data[a];
        ++a;
      } else {
        C.data[i] = B.data[b];
        ++b;
      }
    }
    for (; a < A.num; ++a, ++i) {
      C.data[i] = A.data[a];
    }

    for (; b < B.num; ++b, ++i) {
      C.data[i] = B.data[b];
    }
    C.num = A.num + B.num;
    return Status::Success;
  }
};
class LinkNode {
private:
  struct node {
    Data_Type data;
    node *next;
    node(const Data_Type d = 0) : data(d), next(nullptr) {}
  };
  node *head = new node(0);

public:
  LinkNode(const int n = 0) {
    if (n < 1) {
      return;
    }
    node *p = head;
    for (int i = 0; i < n; i++) {
      node *q = new node;
      std::cin >> q->data;
      p->next = q;
      p = q;
    }
  }
  ~LinkNode() {
    node *p = head;
    while (p != nullptr) {
      node *next = p->next;
      delete p;
      p = next;
    }
    head = nullptr;
  }
  Status IsEmpty() { return head->next == nullptr ? Status::Yes : Status::No; }
  int Size() {
    int i = 0;
    node *p = head->next;
    while (p != nullptr) {
      ++i;
      p = p->next;
    }
    return i;
  }
  Status Get_Data(const int target_index, Data_Type &get_data) {
    if (target_index < 1) {
      get_data = 0;
      return Status::Error_Invalid_Index;
    }
    node *p = head;
    for (int j = 0; j < target_index; j++) {
      if (p == nullptr) {
        get_data = 0;
        return Status::Error_Extra_Index;
      }
      p = p->next;
    }
    get_data = p->data;
    return Status::Success;
  }
  Status Search_data(const Data_Type target_data, int &get_index) {
    int i = 1;
    bool is_found = false;
    for (node *p = head->next; p != nullptr; p = p->next, ++i) {
      if (target_data == p->data) {
        is_found = true;
        break;
      }
    }
    get_index = is_found ? i : 0;
    return is_found ? Status::Success : Status::Waring_Not_Found;
  }
  Status Insert(const Data_Type new_data, const int target_index) {
    if (target_index < 1) {
      return Status::Error_Invalid_Index;
    }
    node *p = head;
    for (int j = 1; j < target_index; j++, p = p->next) {
      if (p == nullptr) {
        return Status::Error_Extra_Index;
      }
    }
    node *k = new node(new_data);
    k->next = p->next;
    p->next = k;
    return Status::Success;
  }
  Status Delete(const int target_index) {
    if (target_index < 1) {
      return Status::Error_Invalid_Index;
    }
    node *p = head;
    for (int j = 1; j < target_index; j++, p = p->next) {
      if (p == nullptr) {
        return Status::Error_Extra_Index;
      }
    }
    if (p->next == nullptr) {
      return Status::Error_Extra_Index;
    }
    node *q = p->next;
    p->next = q->next;
    delete q;
    return Status::Success;
  }
  void print() {
    for (node *p = head->next; p != nullptr; p = p->next) {
      std::cout << p->data << " ";
    }
  }
  void backprint() {
    node *L = new node;
    for (node *head_p = head->next; head_p != nullptr; head_p = head_p->next) {
      node *q = new node(head_p->data);
      q->next = L->next;
      L->next = q;
    }
    for (node *p = L->next, *q = p; p != nullptr; delete q) {
      q = p;
      std::cout << p->data << " ";
      p = p->next;
    }
    delete L;
  }
  void Delete_same_data() {
    for (node *p = head->next; p != nullptr; p = p->next) {
      node *q = p->next, *l = p;
      while (q != nullptr) {
        if (q->data == p->data) {
          l->next = q->next;
          delete q;
          q = l->next;
        } else {
          l = l->next;
          q = q->next;
        }
      }
    }
  }
  friend Status create_node(const LinkNode &A, const LinkNode &B, LinkNode &C) {
    node *p_a = A.head->next;
    node *p_b = B.head->next;
    node *L = new node, *p = L;
    while (p_a != nullptr && p_b != nullptr) {
      if (p_a->data > p_b->data) {
        node *q = new node(p_b->data);
        p->next = q;
        p = q;
        p_b = p_b->next;
      } else {
        node *q = new node(p_a->data);
        p->next = q;
        p = q;
        p_a = p_a->next;
      }
    }
    while (p_a != nullptr) {
      node *q = new node(p_a->data);
      p->next = q;
      p = q;
      p_a = p_a->next;
    }
    while (p_b != nullptr) {
      node *q = new node(p_b->data);
      p->next = q;
      p = q;
      p_b = p_b->next;
    }
    C.head->next = L->next;
    delete L;
    return Status::Success;
  }
};
} // namespace MyLib
int main() {
  std::cout << "测试顺序表还是链表（1.顺序表 2.链表 默认是顺序表）：";
  int m;
  std::cin >> m;
  switch (m) {
  case 2:
    goto Node_Test;
    break;
  case 1:;
  default:
    goto SeqList_Test;
    break;
  }
Node_Test: {
  int n;
  bool node_test_ten = false;
  int index;
  MyLib::Data_Type data;
  std::cout << "初始化大小为n的链表（输入n的值）：";
  std::cin >> n;
  std::cout << "依次输入这" << n << "个元素：";
  MyLib::LinkNode node_test(n);
  std::cout << "1.是否为空链表 " << "2.返回链表长度" << std::endl
            << "3.获得某个下标（从1开始）的元素 " << "4.查找某个元素的下标"
            << std::endl
            << "5.在某个下标插入新元素 " << "6.删除某个下标的元素" << std::endl
            << "7.打印所有元素 " << "8.反向打印所有元素" << std::endl
            << "9.删除所有重复元素 "
               "10.合并两个排序好的链表"
            << std::endl;
  while (true) {
    std::cout << "：";
    std::cin >> n;
    switch (n) {
    case 1:
      if (node_test.IsEmpty() == MyLib::Status::Yes) {
        std::cout << "是空的" << std::endl;
      } else {
        std::cout << "不是空的" << std::endl;
      }
      break;
    case 2:
      std::cout << "长度为：" << node_test.Size() << std::endl;
      break;
    case 3:
      std::cout << "输入下标：";
      std::cin >> index;
      if (node_test.Get_Data(index, data) == MyLib::Status::Success) {
        std::cout << "获得的元素为：" << data << std::endl;
      } else {
        std::cout << "获取失败" << std::endl;
      }
      break;
    case 4:
      std::cout << "输入要查找的元素：";
      std::cin >> data;
      if (node_test.Search_data(data, index) == MyLib::Status::Success) {
        std::cout << "该元素第一次出现在下标" << index << std::endl;
      } else {
        std::cout << "查找失败" << std::endl;
      }
      break;
    case 5:
      std::cout << "输入插入的新元素：";
      std::cin >> data;
      std::cout << "输入插入的下标：";
      std::cin >> index;
      if (node_test.Insert(data, index) == MyLib::Status::Success) {
        std::cout << "插入成功" << std::endl;
      } else {
        std::cout << "插入失败" << std::endl;
      }
      break;
    case 6:
      std::cout << "输入删除元素的下标：";
      std::cin >> index;
      if (node_test.Delete(index) == MyLib::Status::Success) {
        std::cout << "删除成功" << std::endl;
      } else {
        std::cout << "删除失败" << std::endl;
      }
      break;
    case 7:
      node_test.print();
      std::cout << std::endl;
      break;
    case 8:
      node_test.backprint();
      std::cout << std::endl;
      break;
    case 9:
      node_test.Delete_same_data();
      break;
    case 10:
      node_test_ten = true;
      break;
    }
    if (node_test_ten) {
      std::cout << "输入A链表元素个数：";
      std::cin >> n;
      std::cout << "依次输入这" << n << "个元素：";
      MyLib::LinkNode A(n);
      std::cout << "输入B链表元素个数：";
      std::cin >> n;
      std::cout << "依次输入这" << n << "个元素：";
      MyLib::LinkNode B(n);
      MyLib::LinkNode C;
      if (create_node(A, B, C) == MyLib::Status::Success) {
        std::cout << "合并后的C为：";
        C.print();
        std::cout << std::endl;
      }
      break;
    }
  }
  return 0;
}
SeqList_Test: {
  int n;
  bool seqlist_test_ten = false;
  int index;
  MyLib::Data_Type data;
  std::cout << "初始化大小为n的顺序表（输入n的值）：";
  std::cin >> n;
  std::cout << "依次输入这" << n << "个元素：";
  MyLib::LinkNode seqlist_test(n);
  std::cout << "1.是否为空表 " << "2.返回表长度" << std::endl
            << "3.获得某个下标（从1开始）的元素 " << "4.查找某个元素的下标"
            << std::endl
            << "5.在某个下标插入新元素 " << "6.删除某个下标的元素" << std::endl
            << "7.打印所有元素 " << "8.反向打印所有元素" << std::endl
            << "9.删除所有重复元素 "
               "10.合并两个排序好的顺序表"
            << std::endl;
  while (true) {
    std::cout << "：";
    std::cin >> n;
    switch (n) {
    case 1:
      if (seqlist_test.IsEmpty() == MyLib::Status::Yes) {
        std::cout << "是空的" << std::endl;
      } else {
        std::cout << "不是空的" << std::endl;
      }
      break;
    case 2:
      std::cout << "长度为：" << seqlist_test.Size() << std::endl;
      break;
    case 3:
      std::cout << "输入下标：";
      std::cin >> index;
      if (seqlist_test.Get_Data(index, data) == MyLib::Status::Success) {
        std::cout << "获得的元素为：" << data << std::endl;
      } else {
        std::cout << "获取失败" << std::endl;
      }
      break;
    case 4:
      std::cout << "输入要查找的元素：";
      std::cin >> data;
      if (seqlist_test.Search_data(data, index) == MyLib::Status::Success) {
        std::cout << "该元素第一次出现在下标" << index << std::endl;
      } else {
        std::cout << "查找失败" << std::endl;
      }
      break;
    case 5:
      std::cout << "输入插入的新元素：";
      std::cin >> data;
      std::cout << "输入插入的下标：";
      std::cin >> index;
      if (seqlist_test.Insert(data, index) == MyLib::Status::Success) {
        std::cout << "插入成功" << std::endl;
      } else {
        std::cout << "插入失败" << std::endl;
      }
      break;
    case 6:
      std::cout << "输入删除元素的下标：";
      std::cin >> index;
      if (seqlist_test.Delete(index) == MyLib::Status::Success) {
        std::cout << "删除成功" << std::endl;
      } else {
        std::cout << "删除失败" << std::endl;
      }
      break;
    case 7:
      seqlist_test.print();
      std::cout << std::endl;
      break;
    case 8:
      seqlist_test.backprint();
      std::cout << std::endl;
      break;
    case 9:
      seqlist_test.Delete_same_data();
      break;
    case 10:
      seqlist_test_ten = true;
      break;
    }
    if (seqlist_test_ten) {
      std::cout << "输入A表元素个数：";
      std::cin >> n;
      std::cout << "依次输入这" << n << "个元素：";
      MyLib::SeqList A(n);
      std::cout << "输入B表元素个数：";
      std::cin >> n;
      std::cout << "依次输入这" << n << "个元素：";
      MyLib::SeqList B(n);
      MyLib::SeqList C;
      if (create_SeqList(A, B, C) == MyLib::Status::Success) {
        std::cout << "合并后的C为：";
        C.print();
        std::cout << std::endl;
      }
      break;
    }
  }
  return 0;
}
}
