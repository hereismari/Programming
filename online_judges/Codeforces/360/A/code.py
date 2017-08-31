n, m = map(int, raw_input().split())

cont = [0] * n

ans = 0
c = 0
for i in xrange(m):
    l = raw_input()
    flag = False
    for j in xrange(n):
        if l[j] == '0': 
            flag = True
            break

    if flag: c += 1
    else: c = 0

    ans = max(ans, c)

print ans
