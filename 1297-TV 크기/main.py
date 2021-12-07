from math import sqrt

D, H, W = map(int, input().split())
rate = D ** 2 / ((H ** 2) + (W ** 2))
rate = sqrt(rate)

print(int(H * rate), int(W * rate))