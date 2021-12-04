#include <iostream>
using namespace std;

long long numbers[100001];
long long tree[262144];

long long init(int start, int end, int index) {
  if (start == end) {
    tree[index] = numbers[start];
    return tree[index];
  }

  int mid = (start + end) / 2;
  tree[index] = init(start, mid, index * 2) + init(mid + 1, end, index * 2 + 1);
  return tree[index];
}

long long sum(int start, int end, int index, int left, int right) {
  if (left > end || right < start) return 0;

  if (left <= start && right >= end) return tree[index];

  int mid = (start + end) / 2;
  return sum(start, mid, index * 2, left, right) +
         sum(mid + 1, end, index * 2 + 1, left, right);
}

void update(int start, int end, int index, int arr_index, long long value) {
  if (arr_index < start || arr_index > end) return;

  tree[index] += value;
  if (start == end) {
    numbers[arr_index] += value;
  } else {
    int mid = (start + end) / 2;
    update(start, mid, index * 2, arr_index, value);
    update(mid + 1, end, index * 2 + 1, arr_index, value);
  }
}

int main() {
  int N, Q;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> Q;
  for (int i = 0; i < N; i++) cin >> numbers[i];

  init(0, N - 1, 1);

  int x, y, offset, num;
  long long value;
  for (int i = 0; i < Q; i++) {
    cin >> x >> y >> offset >> num;
    if (x > y)  // x > y일 시 스왑
      swap(x, y);

    cout << sum(0, N - 1, 1, x - 1, y - 1) << endl;

    value = num - numbers[offset - 1];
    update(0, N - 1, 1, offset - 1, value);
  }
}