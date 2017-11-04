t = int(raw_input())
MOD = 1000000007

for j in xrange(1, t+1):
  
  c, v, l = map(int, raw_input().split())
 
  dp_v = [1] * (l+1)
  dp_c = [1] * (l+1)
  dp_q = [1] * (l+1) 
 
  for i in xrange(1, l+1):
    dp_v[i] = (dp_q[i-1] * v) % MOD
    dp_c[i] = (dp_v[i-1] * c) % MOD
    dp_q[i] = (dp_c[i] + dp_v[i]) % MOD
  
  print 'Case #%d: %d' % (j, dp_v[l])
