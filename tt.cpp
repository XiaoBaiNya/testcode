#include <iostream>
int main() {
  int a[] = {1, 2, 3, 4, 5, 6};
  int b = std::size(a);
  int i, j, k;
  int n = 0;
  for (int i = 0; i < b - 2; i++) {
    for (int j = i + 1; j < b - 1; j++) {
      if (a[i] < a[j]) {
        for (int k = j + 1; k < b; k++) {
          if (a[j] < a[k]) {
            n++;
          }
        }
      }
    }
  }
  std::cout << n;
}
