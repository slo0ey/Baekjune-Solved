#include <iostream>
#include <vector>
using namespace std;

int N, M;

void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int& count,
         int x, int y, char tile, bool upcount) {
  if (x < 0 || y < 0 || x >= M || y >= N) return;
  if (visited[y][x]) return;

  if (upcount) count++;

  if (tile == board[y][x]) {
    visited[y][x] = true;

    if (tile == '-') {
      dfs(board, visited, count, x - 1, y, tile, false);
      dfs(board, visited, count, x + 1, y, tile, false);
    } else if (tile == '|') {
      dfs(board, visited, count, x, y - 1, tile, false);
      dfs(board, visited, count, x, y + 1, tile, false);
    }
  }
}

int main() {
  cin >> N >> M;

  vector<vector<char>> board(N, vector<char>(M));
  vector<vector<bool>> visited(N, vector<bool>(M, false));
  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dfs(board, visited, count, j, i, board[i][j], true);
    }
  }

  cout << count;
}