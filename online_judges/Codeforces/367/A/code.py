from math import sqrt

x, y = map(int, raw_input().split())
n = int(raw_input())

ans = -1
for i in xrange(n):
    x1, y1, v = map(int, raw_input().split())
    if ans == -1:
        ans = sqrt((x-x1) * (x-x1) + (y-y1)*(y-y1)) / (1.0 * v)
    else:
        ans = min(ans, sqrt((x-x1) * (x-x1) + (y-y1)*(y-y1)) / (1.0 * v))

print ans
