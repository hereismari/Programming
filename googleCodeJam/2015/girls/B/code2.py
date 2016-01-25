n = int(raw_input())

for case in xrange(1, n+1):

    k, v = map(int, raw_input().split())
    ans = 0
    for i in xrange(k+1):
        for j in xrange(k+1):
            for k in xrange(k+1):
                if abs(i-j) <= v and abs(i-k) <= v and abs(j-k) <= v:
                    ans += 1
    print "Case #%d: %d" % (case, ans)
