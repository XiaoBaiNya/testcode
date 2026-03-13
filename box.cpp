/**
 * @Author: XiaoBaiNya
 * @Created: 2026-03-12 22:53:50
 */
#include <iostream>
/**
 * @class Box
 * @brief 创建容器
 *
 */
class Box {
private:
  /**
   * @class data
   * @brief 数据结构
   *
   */
  struct data {
    int x = 0;
    data *previous = nullptr;
    data *next = nullptr;
  };

  data *head;
  int size;

public:
  /**
   * @brief 容器初始化
   *
   * @param num 数据数量 不小于1
   */
  Box(const int &num = 1) : head(nullptr), size(num) {
    if (num < 1) {
      throw std::string("容器数不能小于1");
    } else {
      head = new data;
      data *p2, *p1 = head;
      for (int i = 0; i < num - 1; i++) {
        p2 = new data;
        p2->previous = p1;
        p1->next = p2;
        p1 = p2;
      }
    }
  }
  /**
   * @brief 释放占用内存
   */
  ~Box() { delete_all_data(); }
  /**
   * @brief 显示特定下标的数据
   *
   * @param target 数据下标
   */
  void display_data(const int &target = 0) {
    if (target > size - 1) {
      throw("目标超出容器数");
    } else {
      data *p = head;
      for (int i = 0; i < target; i++) {
        p = p->next;
      }
      std::cout << p->x;
    }
  }
  /**
   * @brief 显示容器内所有数据
   */
  void display_all_data() {
    if (size == 0) {
      throw("null");
    } else {
      for (data *p = head; p != nullptr; p = p->next) {
        std::cout << p->x << " ";
      }
    }
  }
  /**
   * @brief 显示数据个数
   *
   * @return 返回个数
   */
  int display_size() { return size; };
  /**
   * @brief 新增数据
   *
   * @param num 新增数据个数
   */
  void create_data(const int &num = 1) {
    if (num <= 0) {
      throw("创建容器数至少为1");
    } else if (size != 0) {
      data *p;
      for (p = head; p->next != nullptr; p = p->next)
        ;
      data *p2, *p1 = p;
      for (int i = 0; i < num; i++) {
        p2 = new data;
        p2->previous = p1;
        p1->next = p2;
        p1 = p2;
        ++size;
      }
    } else {
      head = new data;
      ++size;
      data *p;
      for (p = head; p->next != nullptr; p = p->next)
        ;
      data *p2, *p1 = p;
      for (int i = 0; i < num - 1; i++) {
        p2 = new data;
        p2->previous = p1;
        p1->next = p2;
        p1 = p2;
        ++size;
      }
    }
  }
  /**
   * @brief 覆盖特定下标数据
   *
   * @param changed_data 修改后的数据
   * @param target 修改的数据下标
   */
  void fill_data(const int &changed_data, const int &target) {
    if (size - 1 < target) {
      throw("容器数不足");
    } else {
      data *p = head;
      for (int i = 0; i < target; i++) {
        p = p->next;
      }
      p->x = changed_data;
    }
  }
  /**
   * @brief 将数据插入到特定下标
   *
   * @param inserted_data 插入的数据
   * @param target 插入的下标
   */
  void insert_data(const int &inserted_data, const int &target) {
    if (target > size - 1) {
      throw("目标超出容器数");
    } else {
      data *new_data = new data;
      data *p = head;
      for (int i = 0; i < target; i++) {
        p = p->next;
      }
      data *p1 = p->previous;
      p->previous = new_data;
      if (p1 != nullptr) {
        p1->next = new_data;
      }
      new_data->next = p;
      new_data->previous = p1;
      new_data->x = inserted_data;
      if (head->previous != nullptr) {
        head = head->previous;
      }
      ++size;
    }
  }
  /**
   * @brief 删除某一下标的数据
   *
   * @param target 被删除的下标
   */
  void delete_data(const int &target) {
    if (target > size - 1) {
      throw("容器数不足");
    } else if (target == 0 && size == 0) {
      throw("无数据");
    } else {
      if (target == size - 1) {
        data *p = head;
        while (p->next != nullptr) {
          p = p->next;
        }
        data *p1 = p->previous;
        p1->next = nullptr;
        delete p;
        --size;
      } else if (target == 0) {
        data *p = head;
        head = head->next;
        head->previous = nullptr;
        delete p;
        --size;
      } else {
        data *p = head;
        for (int i = 0; i < target; i++) {
          p = p->next;
        }
        data *p1 = p->previous, *p2 = p->next;
        p1->next = p2;
        p2->previous = p1;
        delete p;
        --size;
      }
    }
  }
  /**
   * @brief 删除容器内所有数据
   */
  void delete_all_data() {
    if (size != 0) {
      for (data *p = head->next; p != nullptr; p = p->next) {
        delete head;
        head = p;
      }
      delete head;
      head = nullptr;
      size = 0;
    }
  }
};
