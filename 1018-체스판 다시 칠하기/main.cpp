#include <iostream>

#define min(a, b) a < b ? a : b

char TYPE[2] = {'W', 'B'};

int main() {
  int M, N;
  char map[50][50];
  int mn = 100;
  std::cin >> N >> M;
  for (int i = 0; i < N; i++) {
    std::cin >> map[i];
  }

  int cw = 0;
  int cb = 0;
  int pos, type;
  for (int i = 0; i < N - 7; i++) {
    for (int j = 0; j < M - 7; j++) {
      for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
          pos = y * 8 + x;
          type = (y % 2) ^ (pos % 2);
          if (type == 0) {
            if (map[i + y][j + x] == 'W') {
              cb++;
            } else {
              cw++;
            }
          } else {
            if (map[i + y][j + x] == 'W') {
              cw++;
            } else {
              cb++;
            }
          }
        }
      }
      mn = min(cw, mn);
      mn = min(cb, mn);
      cw = 0;
      cb = 0;
    }
  }

  std::cout << mn;
}