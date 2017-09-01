t = int(raw_input())

for i in xrange(1, t+1):

    n = int(raw_input())
    p = map(float, raw_input().split())

    p.sort()

    res = p[0] * p[2*n-1]
    acum = (1 - p[0]) + (p[0] * (1 - p[2*n-1]))
    for j in xrange(1, n):
        res = res + acum * p[j] * p[2*n-1-j]
        acum = acum * ((1 - p[j]) + (p[j] * (1 - p[2*n-1-j])))

    print 'Case #%d:' % (i), 1 - res
