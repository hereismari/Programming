from math import ceil

n, h, k = map(int, raw_input().split())
l = map(int, raw_input().split())

ans = []
used = 0
cont = 0

for i in xrange(n):

    if(used + l[i] > h):
        used = 0
        cont += 1

    used += l[i]
    cont += (used/k)
    used = max(used - (used/k) * k, 0)
    
if used > 0: cont += 1
print cont
