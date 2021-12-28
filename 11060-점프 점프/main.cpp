#include <iostream>

#define BIG 1000000
using namespace std;

int N;
int maze[1000];
int cache[1000];

int min(int a, int b) { return a < b ? a : b; }

int DP(int pos, int jump) {
  if (pos >= N)
    return BIG;

  int &val = cache[pos];
  if (jump >= val)
    return BIG;
  val = jump;

  if (pos == N - 1)
    return jump;

  int mn = BIG;
  for (int i = maze[pos]; i >= 1; i--)
    mn = min(mn, DP(pos + i, jump + 1));

  return mn;
}

int main() {
  int ans;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> maze[i];
    cache[i] = BIG;
  }
  ans = DP(0, 0);

  if (cache[N - 1] >= BIG)
    cout << -1;
  else
    cout << ans;
}