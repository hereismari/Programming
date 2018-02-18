t = int(raw_input())

for r in xrange(1, t+1):

  k, v = map(int, raw_input().split())
  
  if v == 0:
    res = k + 1
  elif v > k:
    res = (k+1) ** 3
  else:
    res = 0
  
    cont = 0
    for i in xrange(k + 1):
        # print i
        up = (v+1) ** 2
        if i + v > k:
          up = (k-i+1) ** 2
        down = (v+1) ** 2
        if i - v < 0:
          down = (i+1) ** 2
          
        res += up + down - 1

        if i == 0 or i == k:
          continue
        
        # go down
        c = 0
        for j in xrange(i-1, max(0, i - v) -1, -1):
          c += 1
          # print i, min(k-i, i+v+c)
          res += min(k-i, i+v+c)
        
        # go up
        c = 0
        for j in xrange(i+1, min(k+1, i + v)):
          c += 1
          # print i, min(i, i+v+c)
          res += min(i, i+v+c)
        
        cont += 1

  print 'Case #%d:' % r, res
