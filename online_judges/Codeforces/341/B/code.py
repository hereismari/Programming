MAX = 1002
tab = []
vis = []

for i in xrange(MAX):
    tab.append([])
    vis.append([])
    for j in xrange(MAX):
        tab[i].append(0)
        vis[i].append(False)

def check1(x, y):
    res = 0
    while x < MAX and y < MAX:
        res += tab[x][y]
        vis[x][y] = True
        x += 1
        y += 1
    return res

def check2(x, y):
    res = 0
    while x < MAX and y > 0:
        res += tab[x][y]
        vis[x][y] = True
        x += 1
        y -= 1
    return res

n = int(raw_input())

for i in xrange(n):
    x, y = map(int, raw_input().split())
    tab[x][y] = 1

ans = 0
for i in xrange(MAX):
    for j in xrange(MAX):
        if not vis[i][j]: 
           res = check1(i,j)
           ans += (res * (res-1)) / 2

for i in xrange(MAX):
    for j in xrange(MAX):
        vis[i][j] = False

for i in xrange(MAX):
    for j in xrange(MAX):
        if not vis[i][j]: 
            res = check2(i,j)
            ans += (res * (res-1)) / 2

print ans
