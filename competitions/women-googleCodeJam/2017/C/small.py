t = int(raw_input())

for i in xrange(1, t+1):

  d, n = map(int, raw_input().split())
  
  m = [['/' for j in xrange(d)] for k in range(d)]
  
  r = 0
  c = 0
  while n > 0:
    if c + 2 >= d:
      if r % 2 == 0:
        c = 0
      else:
        c = 1
      r += 1
    else:
      m[r][c] = 'I'
      m[r][c+2] = 'O'
      c += 3
      n -= 1
  
  print 'Case #%d:' % (i)
  for j in xrange(d):
    print ''.join(m[j])
