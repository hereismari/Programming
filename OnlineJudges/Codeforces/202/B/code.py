n = int(raw_input())
l = map(int, raw_input().split())

m = []

for i in xrange(1, 10):
    m.append([l[i-1], i])

m.sort()
print m



