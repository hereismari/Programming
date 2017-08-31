n, m = map(int, raw_input().split())

a = [0] * (m + 1)
for i in xrange(n):
    l = map(int, raw_input().split())
    for i in xrange(1, len(l)):
        a[l[i]] = 1

if sum(a) == m: print 'YES'
else: print 'NO'
