t = int(raw_input())

while t > 0:

    t -= 1

    s, c, r = map(int, raw_input().split())

    v = map(int, raw_input().split())
    v.sort()

    ans = 0
    cont = 0

    for i in xrange(s):
        if i < c:
            ans += 1.0/(v[i] + r)
        else:
            ans += 1.0/v[i]
    print "%.2f" % ans
