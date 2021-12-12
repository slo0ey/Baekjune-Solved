import sys
input = sys.stdin.readline;

dx = [-1, 0, 1, 1, 1, 0, -1, -1]
dy = [-1, -1, -1, 0, 1, 1, 1, 0]

T = int(input())
N = 0
count = 0
q = []

def bfs(board: list[str], visited: list[list[bool]], x: int, y: int):
  if x < 0 or y < 0 or x >= N or y >= N:
    return
  if visited[y][x]:
    return
  
  visited[y][x] = True
  if board[y][x] == "-":
    global count
    count += 1
    q.append([x, y])

for i in range(T):
  N = int(input())
  count = 0

  board = []
  visited = [[False] * N for _ in range(N)]

  for _ in range(N):
    board.append(input())

  for j in range(N):
    for k in range(N):
      if board[j][k] == "w":
        visited[j][k] = True
        q.append([k, j])

        while len(q) != 0:
          queue_size = len(q)

          while queue_size > 0:
            x, y = q.pop()

            for m in range(8):
              bfs(board, visited, x + dx[m], y + dy[m])

            queue_size -= 1

  print(count)