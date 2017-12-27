n, m = map(int, raw_input().split())

prev_y = 0
for i in xrange(n):
  x, y = map(int, raw_input().split())
  if x > prev_y:
    break
  
  prev_y = max(prev_y, y)

if prev_y >= m:
  print 'YES'
else:
  print 'NO'
