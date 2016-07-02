n, x = map(int, raw_input().split())

cont = 0
for i in xrange(n):
    c, k = raw_input().split()
    k = int(k)

    if c == '+': x += k
    else:
        if x >= k: x -= k
        else: cont += 1

print x, cont
