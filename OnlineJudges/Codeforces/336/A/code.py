n, s = map(int, raw_input().split())

a = [0] * 1001

while n > 0:
    
   x, y = map(int, raw_input().split())
   a[x] = max(a[x],y)
   n -= 1

last = s
ans = 0
aux = 0

for i in xrange(s, -1, -1):
    if a[i] != 0:
        ans += (last - i)
        if a[i] > ans: ans += (a[i] - ans)
        last = i

print ans + last
