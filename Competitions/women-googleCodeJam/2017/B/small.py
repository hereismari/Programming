import itertools

t = int(raw_input())

for i in xrange(1, t+1):

    n = int(raw_input())
    p1 = map(float, raw_input().split())

    p1.sort()

    res1 = 1
    for p in itertools.permutations(p1):
        res = p[0] * p[n]
        acum = (1 - p[0]) + (p[0] * (1 - p[n]))
        for j in xrange(1, n):
            res = res + acum * p[j] * p[j+n]
            acum = acum * ((1 - p[j]) + (p[j] * (1 - p[j + n])))

        res1 = min(res1, res)

    print 'Case #%d:' % (i), 1 - res1
