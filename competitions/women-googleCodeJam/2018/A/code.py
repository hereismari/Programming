def get_order(k):
  if k % 2 == 0:
    return range(k/2) + range(k/2-1, -1, -1)
  else:
    return range((k-1)/2) + range((k-1)/2, -1, -1) 

t = int(raw_input())

for c in xrange(1, t+1):

  n = int(raw_input())
  
  order = get_order(n)
  #print order
  l = map(int, raw_input().split())
  l.sort()
  #print l
  
  b = 0
  e = n-1
  i = 0
  ans = 0
  while i+1 < n:
    ans += (l[i]-order[b])**2
    ans += (l[i+1]-order[e])**2
    b += 1
    e -= 1
    i += 2

  if n % 2 == 1:
    ans += (l[-1]-order[n/2])**2

  print 'Case #%d:' % c, ans
