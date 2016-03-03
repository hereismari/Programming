n = int(raw_input())

cost = 1000
ans = 0
for i in xrange(n):
    q, p = map(int,raw_input().split())
    cost = min(p, cost)
    ans += q * cost

print ans
