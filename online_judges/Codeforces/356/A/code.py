m = map(int, raw_input().split())

x = [0] * 101

s = sum(m)

for e in m: x[e] += 1

aux = 0
for e in m:
    if x[e] >= 2:
        aux = max(aux, min(3, x[e]) * e)

print s - aux

