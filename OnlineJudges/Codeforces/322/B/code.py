n = int(raw_input())
l = map(int, raw_input().split())
m = [0]*n
max_value = 0
for i in xrange(n-1, -1,-1):
    max_value = max(max_value, l[i])
    m[i] = max_value
 
for i in xrange(n-1):
    ans = m[i+1] - l[i]
    if ans < 0: ans = 0
    else: ans += 1
    print ans,

print 0
