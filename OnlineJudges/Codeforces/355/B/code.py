n, h, k = map(int, raw_input().split())
l = map(int, raw_input().split())
ans = []

i = 0
used = 0
cont = 0

while i < n or used > 0:

    while i < n and l[i] + used <= h: 
        used += l[i]
        cont += 1
        print 1, used, cont
        i += 1

    if i < n:
        used = max((used - l[i]), k)/k * k
        cont += (used - l[i])/k
        print used
        cont += max((l[i])/k, 1)
        i += 1
        print 2, used, cont

    else:
        cont += used/k
        used = 0
print cont
