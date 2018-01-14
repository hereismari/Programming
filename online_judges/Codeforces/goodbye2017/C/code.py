import math

def solve(x2, x1, y1, r):
  a = 1
  b = -2 * y1
  c = ((x2-x1) * (x2-x1)) + y1 * y1 + -4 * r * r
  delta = b * b - 4 * a * c
  #print delta, a, b, c
  if delta >= 0:
    res = (-1 * b + math.sqrt(delta))/(2 * a)
  else:
    res = r
  #print res
  return res
  
n, r = map(int, raw_input().split())
x = map(int, raw_input().split())

h = [r]


for i in xrange(1, n):
  index = -1
  y = r  
  for j in xrange(i):
    if abs(x[i]-x[j]) <= 2 * r:
      # collision
      res = solve(x[i], x[j], h[j], r)
      y = max(y, res)
  
  h.append(y)
    
for e in h:
  print e,
