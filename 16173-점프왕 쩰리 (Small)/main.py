import sys
input = sys.stdin.readline

N = int(input())

board = []
visited = [[False] * N for _ in range(N)]
queue = [[0, 0]]

for _ in range(N):
  board.append(list(map(int, input().split())))

def bfs(x: int, y: int):
  if x >= N or y >= N: return
  if visited[y][x]: return

  visited[y][x] = True
  queue.append([x, y])

while len(queue) != 0:
  queue_size = len(queue)

  for _ in range(queue_size):
    x, y = queue.pop()
    jump = board[y][x]

    if jump == -1:
      print("HaruHaru")
      exit(0)
    
    bfs(x + jump, y)
    bfs(x, y + jump)

    queue_size -= 1

print("Hing")