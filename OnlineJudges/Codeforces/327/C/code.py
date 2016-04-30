n = int(raw_input())
l = map(int, raw_input().split())

dist = []

for i in xrange(n-1):

    if i == 0: dist.append((0, l[i]))
    else:
        if l[i-1] == l[i] or l[i] == l[i+1]:
            dist.append((0, l[i]))
        else:
            dist.append((dist[i-1][0]+1, dist[i-1][1]))

dist.append((0, l[n-1]))

ans = 0
for i in xrange(n-1, 0, -1):

    if i == n-1: dist[i] = (0, l[i])
    else:
        if l[i-1] == l[i] or l[i] == l[i+1]:
            continue
        else:
            if dist[i+1][0] + 1 < dist[i][0]:
                dist[i] = (dist[i+1][0] + 1, dist[i+1][1])
            ans = max(ans, dist[i][0])

for i in xrange(1, n-1):
    if dist[i][0] != 0: l[i] = dist[i][1]

print ans
for e in l: print e,
