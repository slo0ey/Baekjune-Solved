N, T, C, P = map(int, input().split())
days = 1
sum = 0

days += T
while(days <= N):
  sum += C * P
  days += T

print(sum)