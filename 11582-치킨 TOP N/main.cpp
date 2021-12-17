#include <iostream>
using namespace std;

int N, k;
int* arr;
int* map;

void merge(int start, int mid, int end) {
  int left = start, right = mid + 1, offset = start;

  while (left <= mid && right <= end) {
    if (arr[left] > arr[right])
      map[offset++] = arr[right++];
    else
      map[offset++] = arr[left++];
  }

  while (left <= mid) map[offset++] = arr[left++];

  while (right <= end) map[offset++] = arr[right++];

  for (int i = start; i < end + 1; i++) arr[i] = map[i];
}

void mergeSort(int start, int end) {
  if (end > start) {
    int mid = (end + start) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);

    if (N / (end - start + 1) >= k) merge(start, mid, end);
  }
}

int main() {
  cin >> N;
  arr = new int[N];
  map = new int[N];
  for (int i = 0; i < N; i++) cin >> arr[i];
  cin >> k;

  mergeSort(0, N - 1);
  for (int i = 0; i < N; i++) cout << arr[i] << " ";

  delete[] arr;
  delete[] map;
}