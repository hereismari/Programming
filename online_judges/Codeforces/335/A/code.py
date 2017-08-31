balls  = map(int, raw_input().split())
wish = map(int, raw_input().split())


res = 0
for i in xrange(3):
    if balls[i] > wish[i]:
        res += (balls[i] - wish[i]) / 2
    else:
        res -= (- balls[i] + wish[i])

ans = res >= 0
if ans: print 'Yes'
else: print 'No'
