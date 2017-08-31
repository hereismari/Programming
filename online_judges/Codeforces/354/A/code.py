n = int(raw_input())
l = map(int, raw_input().split())

ma = max(l)
mi = min(l)
i_ma = 0
i_mi = 0
for i in xrange(len(l)):
    if(ma == l[i]): i_ma = max(i+1, len(l) - i)
    if(mi == l[i]): i_mi = max(i+1, len(l) - i)

print max(i_ma-1, i_mi-1)
