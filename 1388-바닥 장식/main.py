import sys
input = sys.stdin.readline

N, M = map(int, input().split())

board = []
visited = [[False] * M for _ in range(N)]
count = 0

for i in range(N):
  board.append(input())

def dfs(x: int, y: int, tile: str, upcount: bool = False):
  if x < 0 or y < 0 or x >= M or y >= N: return
  if visited[y][x]: return

  global count
  if upcount: count += 1

  if(board[y][x] == tile):
    visited[y][x] = True

    if tile == "-":
      dfs(x - 1, y, tile)
      dfs(x + 1, y, tile)
    elif tile == "|":
      dfs(x, y - 1, tile)
      dfs(x, y + 1, tile)

for i in range(N):
  for j in range(M):
    dfs(j, i, board[i][j], True)

print(count)