n, m = map(int,raw_input().split())

l = []
for i in xrange(n):
    l.append(raw_input().split())

cont = 0

for i in xrange(n):
    j = 0
    while j < 2*m:
        if (l[i][j] == '1' or l[i][j+1] == '1'): cont += 1
        j += 2

print cont
