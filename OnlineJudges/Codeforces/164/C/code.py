n, m = map(int,raw_input().split())

print min(m,n) + 1
for i in xrange(min(m,n),-1, -1):
    print i, min(m,n) - i
