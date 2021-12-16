#include <iostream>
using namespace std;

int N;
int _count = 0;

void dfs(int start, int digit) {
  if (digit == N) {
    if (start % 3 == 0) _count++;
  } else {
    dfs(start + 0, digit + 1);
    dfs(start + 1, digit + 1);
    dfs(start + 2, digit + 1);
  }
}

int main() {
  cin >> N;
  dfs(1, 1);
  dfs(2, 1);
  cout << _count;
}