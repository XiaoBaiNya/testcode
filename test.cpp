#include <iostream>

int main() {
  int a[] = {1, 2, 3, 4, 5, 6};
  int n = std::size(a);
  int b = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = 1 + i; j < n - 1; j++) {
      for (int k = 1 + j; k < n; k++) {
        if (a[i] < a[j] && a[j] < a[k]) {
          b++;
        }
      }
    }
  }
  std::cout << b;
}
