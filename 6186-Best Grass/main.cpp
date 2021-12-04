#include <iostream>

#define is_unsafe_pos(x, y, R, C) x < 0 || y < 0 || x >= C || y >= R

int R, C;
int count;
char map[100][100];
bool check[100][100];
int around[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void deep_check(int x, int y, int R, int C) {
  check[y][x] = true;
  int dx, dy;
  for (int i = 0; i < 4; i++) {
    dx = x + around[i][0];
    dy = y + around[i][1];
    if (is_unsafe_pos(dx, dy, R, C)) continue;
    if (!check[dy][dx] && map[dy][dx] == '#') deep_check(dx, dy, R, C);
  }
}

int main() {
  std::cin >> R >> C;
  for (int i = 0; i < R; i++) {
    std::cin >> map[i];
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (!check[i][j] && map[i][j] == '#') {
        deep_check(j, i, R, C);
        count++;
      }
    }
  }

  std::cout << count;
}