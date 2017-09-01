t = int(raw_input())

for i in xrange(1, t+1):

    f, s = map(int, raw_input().split())

    q = []
    for j in xrange(s + 1):
        q.append([])

    for j in xrange(f):
        x, y = map(int, raw_input().split())

        q[x].append(y)
        q[y].append(x)

    res = 0
    for j in xrange(1, len(q)):
        res = max(res, len(set(q[j])))

    print 'Case #%d:' % (i), res
