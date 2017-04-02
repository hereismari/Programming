t = int(raw_input())

for i in xrange(1, t+1):

    k, v = map(int, raw_input().split())

    res = ((v+1) * (v+1) * (v+1))
    j = k-v-1
    while j >= 0:
        res += 1 * (v+1) * (v+1)
        res += v * 1 * (v+1)
        j -= 1

    print 'Case #%d:' % (i), res
