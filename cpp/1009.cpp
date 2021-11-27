#include <iostream>

int table[10][4] = {{10, 10, 10, 10}, {1, 1, 1, 1}, {2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6, 4, 6}, {5, 5, 5, 5}, {6, 6, 6, 6}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1, 9, 1}};

int main() {
  int T;
  int a, b;
  std::cin >> T;
  for (int i = 0; i < T; i++) {
    std::cin >> a >> b;
    std::cout << table[a % 10][(b - 1) % 4] << std::endl;
  }
}