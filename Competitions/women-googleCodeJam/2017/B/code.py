t = int(raw_input())

for i in xrange(1, t+1):

    n = int(raw_input())
    p = map(float, raw_input().split())

    p.sort()

#    print p
    res = p[0] * p[n]
    acum = (1 - p[0]) + (p[0] * (1 - p[n]))
    for j in xrange(1, n):
        res = res + acum * p[j] * p[j+n]
        acum = acum * ((1 - p[j]) + (p[j] * (1 - p[j + n])))

    print 'Case #%d:' % (i), 1 - res
