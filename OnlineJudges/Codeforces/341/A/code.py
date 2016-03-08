n = int(raw_input())
l = map(int, raw_input().split())

l.sort()

cont = 0
for e in l:
    if e % 2 == 1: 
        cont += 1

ans = 0
if cont % 2 == 1:
    cont -= 1

for i in xrange(len(l)-1, -1, -1):
    if l[i] % 2 == 1 and cont > 0:
        cont -= 1
        ans += l[i]
    elif l[i] % 2 == 0:
        ans += l[i]

print ans
