import sys
input = sys.stdin.readline

N = int(input())
count = 0

def dfs(start: int, digit: int):
  if digit == N:
    if start % 3 == 0:
      global count
      count += 1
  else:
    dfs(start+0, digit+1)
    dfs(start+1, digit+1)
    dfs(start+2, digit+1)

dfs(1, 1)
dfs(2, 1)
print(count)