/**
 * @Author: XiaoBaiNya
 * @Created: 2026-04-18 17:13:43
 * @Encoding: utf-8
 * @Indent: 2 spaces
 */

#include <iostream>
#include <string>
#include <vector>
int main() {
  std::string str1 = "ababaabbababaababaababaabbbababbaaabaaabbaabab";
  std::string str2 = "a";
  std::string str3 = str2 + '#' + str1;
  std::vector<int> a(str3.size(), 0);
  size_t s = 0;
  for (size_t i = 1; i < str3.size(); ++i) {
    size_t p1 = a[i - 1];
    while (p1 != 0 && str3[i] != str3[p1]) {
      p1 = a[p1 - 1];
    }
    if (str3[i] == str3[p1]) {
      a[i] = p1 + 1;
    }
    if (a[i] == str2.size()) {
      ++s;
    }
  }
  std::cout << s << std::endl;
  for (size_t i = 0; i < str3.size(); ++i) {
    if (a[i] == str2.size()) {
      std::cout << i - str2.size() * 2 + 1 << " ";
    }
  }
}
