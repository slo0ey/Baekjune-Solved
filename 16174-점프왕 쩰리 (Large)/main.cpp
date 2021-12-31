#include <iostream>
#include <queue>
using namespace std;

int N;
int map[64][64];
bool visited[64][64];
queue<int> list;

void bfs(int x, int y) {
  if (x >= N || y >= N)
    return;
  if (visited[y][x])
    return;

  visited[y][x] = true;
  list.push(y * N + x);
}

int main() {
  int list_size;
  int pos, x, y, jump;

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
      visited[i][j] = false;
    }
  }

  list.push(0);
  while (!list.empty()) {
    list_size = list.size();

    while (list_size > 0) {
      pos = list.front();
      list.pop();
      x = pos % N;
      y = pos / N;
      jump = map[y][x];

      if (jump == -1) {
        cout << "HaruHaru";
        return 0;
      }

      bfs(x + jump, y);
      bfs(x, y + jump);
      list_size--;
    }
  }

  cout << "Hing";
}