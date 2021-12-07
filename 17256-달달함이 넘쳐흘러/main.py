def cake(ax: int, ay: int, az: int, cx: int, cy: int, cz: int):
  return (cx - az, int(cy / ay), cz - ax)

ax, ay, az = map(int, input().split())
cx, cy, cz = map(int, input().split())
bx, by, bz = cake(ax, ay, az, cx, cy, cz)

print(bx, by, bz)