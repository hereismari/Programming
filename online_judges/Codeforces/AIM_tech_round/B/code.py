n = int(raw_input())
l = map(int, raw_input().split())

l.sort()

aux = 100000000000
ans = 0

for i in xrange(n-1, -1, -1):
    if l[i] < aux:
        ans += l[i]
        aux = l[i]
    else:
        ans += max(0, aux - 1) 
        aux = max(0, aux - 1)
 
print ans
