t, k = map(int, raw_input().split())
for i in xrange(t):
    n, m  = map(int, raw_input().split())
    if (n + m) % 2 or (n-k == 1 and m-k == 1): print '+'
    else: print '-'
