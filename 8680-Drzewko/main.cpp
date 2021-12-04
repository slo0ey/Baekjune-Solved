#include <iostream>

int main() {
  int N, h;
  std::cin >> N >> h;

  N = N - 1;
  int t, result = 0;
  for (int i = 0; i < h; i++) {
    t = (N >> i) % 2;
    result |= (t << (h - i - 1));
  }

  std::cout << result;
}