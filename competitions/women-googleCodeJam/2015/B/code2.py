t = int(raw_input())

for j in xrange(1, t+1):

  k, v = map(int, raw_input().split())
  
  if v == 0:
    res = k + 1
  else:
    res = 0
  
    # count up
    cont = 0
    for i in xrange(min(v, k) + 1):
        up = (v+1) ** 2 - 1
        if i + v > k:
          up = (k-i+1) ** 2 - 1
        down = (v+1) ** 2
        if i - v < 0:
          down = (i+1) ** 2 - 1
        # print up + down
        res += up + down
        cont += 1
    
    
    if cont <= k:
      # count down
      for i in xrange(k, max(k-v, v)-1, -1):
        up = (v+1) ** 2 - 1
        if i + v > k:
          up = (k-i+1) ** 2 - 1
        down = (v+1) ** 2
        if i - v < 0:
          down = (i+1) ** 2 - 1
        # print up + down
        res += up + down
        cont += 1

    # rest
    if cont <= k:
      d = k - 2 * v - 1
      up = (v+1) ** 2
      down = (v+1) ** 2
      res += (up + down) * d - 2 * d
      
  print 'Case #%d:' % j, res
