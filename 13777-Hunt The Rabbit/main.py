trace = []

def binary_search(start: int, end: int, result: int):
  mid = (start + end) // 2
  trace.append(str(mid))

  if mid == result:
    return
  
  if result < mid:
    binary_search(start, mid - 1, result)
  else :
    binary_search(mid + 1, end, result)

c = int(input())
while (c != 0):
  binary_search(1, 50, c)
  print(" ".join(trace))
  trace.clear()
  c = int(input())