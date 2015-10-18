n = int(raw_input())
m1 = {}
m2 = {}
cont = 0
for i in xrange(n*n):
    x, y = map(int, raw_input().split())
    if x in m1 or y in m2: continue
    print i+1,
    m1[x] = 1
    m2[y] = 1
