import sys;
sys.setrecursionlimit(2**21)
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
k = int(input())

tmp = [0 for _ in range(N)]

def merge(start: int, mid: int, end: int):
  left = start
  right = mid + 1
  offset = start

  while left <= mid and right <= end:
    if arr[left] > arr[right]:
      tmp[offset] = arr[right]
      right += 1
    else:
      tmp[offset] = arr[left]
      left += 1
    offset += 1

  while left <= mid:
    tmp[offset] = arr[left]
    offset += 1
    left += 1

  while right <= end:
    tmp[offset] = arr[right]
    offset += 1
    right += 1

  for i in range(start, end+1):
    arr[i] = tmp[i]

def mergeSort(start: int, end: int):
  if end > start:
    mid = (end + start) // 2
    mergeSort(start, mid)
    mergeSort(mid+1, end)

    if (N // (end-start+1)) >= k:
      merge(start, mid, end)

mergeSort(0, N-1)
print(" ".join(arr))