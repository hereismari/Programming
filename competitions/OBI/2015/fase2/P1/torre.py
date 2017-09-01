n = int(raw_input())

m = []
for i in xrange(n):
    m.append(map(int,raw_input().split()))

ans = [[0 for j in xrange(n)] for i in xrange(n)]
for i in xrange(n):
    s = 0
    for j in xrange(n):
        s += m[i][j]
        ans[i][j] -= m[i][j]
    for j in xrange(n):
        ans[i][j] += s
for j in xrange(n):
    s = 0
    for i in xrange(n):
        s += m[i][j]
        ans[i][j] -= m[i][j]
    for i in xrange(n):
        ans[i][j] += s

print max(max(ans))


