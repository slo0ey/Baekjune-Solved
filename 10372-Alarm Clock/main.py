seg_count = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

n = int(input())

if n < 8 or n > 26:
  print("Impossible")
  exit(0)

for hour in range(24):
  test = n
  test -= seg_count[hour // 10]
  test -= seg_count[hour % 10]

  if 4 <= test and test <= 13:
    minute = 0

    for d1 in range(6):
      for d2 in range(10):
        if seg_count[d1] + seg_count[d2] == test:
          minute += d1 * 10 + d2

          print("%02d:%02d" % (hour, minute))
          exit(0)