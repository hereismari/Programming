t = int(raw_input())

for c in xrange(1, t+1):

  n = int(raw_input())
  
  a = [0] * 1010
  m = 0
  for i in xrange(n):
    k, e = map(int, raw_input().split())
    a[e] += k
    m = max(m, e)
  
  ans = m+1
  #print ans
  non_par = a[0]
  for j in xrange(1, m+1):
    #print j, non_par
    if non_par > 0:
      if a[j] * j >= non_par:
        non_par = 0
      else:
        non_par -= a[j] * j
    non_par += a[j]

  #print(non_par)
  if non_par > ans: ans = non_par

  print 'Case #%d:' % c, ans
