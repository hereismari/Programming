n = int(raw_input())

for case in xrange(1, n+1):

    k, v = map(int, raw_input().split())
    ans = (k+1) ** 3
    for i in xrange(k+1):
        value = 0
        if i - (v+1) >= 0: value += i - (v+1) + 1
        if i + (v+1) <= k: value += k - (i+v+1) + 1
        value *= (k+1)
        print value
        ans -= value

    print "Case #%d: %d" % (case, ans)
