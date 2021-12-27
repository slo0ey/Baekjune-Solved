#include <string.h>

#include <iostream>
#include <queue>
using namespace std;

int n, ans = 0;
int arr[1000];
int dist[1000];

int max(int a, int b) { return a > b ? a : b; }

int DP(int start, int offset, int sum) {
  if (sum <= dist[start]) return sum;

  dist[start] = sum;
  int mx = sum;
  for (int i = start + 1; i < n; i++) {
    if (offset < arr[i]) mx = max(DP(i, arr[i], sum + 1), mx);
  }
  return mx;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  memset(dist, 0, sizeof(dist));

  for (int i = 0; i < n; i++) ans = max(DP(i, arr[i], 1), ans);

  cout << ans;
  return 0;
}