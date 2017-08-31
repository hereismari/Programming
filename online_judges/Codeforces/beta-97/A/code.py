n = int(raw_input())
l = map(int, raw_input().split())

m = {}
cont = 1
for e in l: 
    m[e] = cont
    cont += 1

for i in xrange(1, n+1):
    print m[i],
