#include <iostream>
#include <vector>
using namespace std;

int virus = 0;

void dfs(vector<vector<int>>& web, vector<bool>& visited, int start) {
  virus++;
  visited[start] = true;

  for (auto c : web[start]) {
    if(!visited[c])
      dfs(web, visited, c);
  }
}

int main() {
  int N, T, from, to;
  cin >> N;
  cin >> T;

  vector<vector<int>> web(N + 1);
  vector<bool> visited(N + 1, false);

  for (int i = 0; i < T; i++) {
    cin >> from >> to;
    web[from].push_back(to);
    web[to].push_back(from);
  }

  dfs(web, visited, 1);
  cout << virus - 1;
}