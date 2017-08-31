n = int(raw_input())
p = map(int, raw_input().split())
prizes = map(int, raw_input().split())

ans = [0] * 5
points = 0

for e in p:
    points += e
    for i in xrange(4,-1,-1):
        ans[i] += points/prizes[i]
        points -= (points/prizes[i]) * prizes[i]

for e in ans: 
    print e,
print
print points

