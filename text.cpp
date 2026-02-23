#include <iostream>
#include <thread>
int main() {
  std::string otext;
  std::getline(std::cin, otext);
  for (int i = 0; i < otext.size(); i++) {
    std::string otext_divide = otext.substr(0, i);
    for (char otext_change = 33; otext_change <= otext[i]; otext_change++) {
      std::cout << otext_divide << otext_change << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
  }
}
