#include <iostream>
using namespace std;

void binary_search(int start, int end, int result) {
  int mid = (start + end) / 2;
  cout << mid << " ";

  if (mid == result) return;

  if (result < mid)
    binary_search(start, mid - 1, result);
  else
    binary_search(mid + 1, end, result);
}

int main() {
  int C;
  cin >> C;

  while (C != 0) {
    binary_search(1, 50, C);
    cout << endl;
    cin >> C;
  }
}