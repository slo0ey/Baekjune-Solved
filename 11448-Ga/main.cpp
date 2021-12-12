#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

int N, wcount;
queue<pair<int, int>> q;

void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x,
         int y) {
  if (x < 0 || y < 0 || x >= N || y >= N) return;
  if (visited[y][x]) return;

  visited[y][x] = true;
  if (board[y][x] == '-') {
    wcount++;
    q.push(make_pair(x, y));
  }
}

int main() {
  int T, queue_size;
  pair<int, int> pos;
  int x, y;
  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> N;
    wcount = 0;

    vector<vector<char>> board(N, vector<char>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++) cin >> board[j][k];

    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (board[j][k] == 'w') {
          visited[j][k] = true;
          q.push(make_pair(k, j));

          while (q.size() != 0) {
            queue_size = q.size();

            while (queue_size > 0) {
              pos = q.front();
              q.pop();
              x = pos.first;
              y = pos.second;

              for (int l = 0; l < 8; l++)
                bfs(board, visited, x + dx[l], y + dy[l]);

              queue_size--;
            }
          }
        }
      }
    }

    cout << wcount << endl;
  }
}