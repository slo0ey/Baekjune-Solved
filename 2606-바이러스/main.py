import sys
input = sys.stdin.readline

virus = 0

def dfs(web: list[list[int]], visited: list[bool], start: int):
  global virus
  virus += 1
  visited[start] = True

  for c in web[start]:
    if not visited[c]:
      dfs(web, visited, c)

N = int(input())
T = int(input())

web = [[] for _ in range(N + 1)]
visited = [False for _ in range(N + 1)]

for i in range(T):
  X, Y = map(int, input().split())
  web[X].append(Y)
  web[Y].append(X)

dfs(web, visited, 1)
print(virus - 1)