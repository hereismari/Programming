t = int(raw_input())

A1 = 'QWERTYUIOPLKJHGFDSAZXCVBNM'
A2 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
def solve(res, alpha, passwords):

    for p in passwords:
        if p in A1 and p in A2:
            return 'IMPOSSIBLE'
        elif p not in A1:
            return A1
        else:
            return A2

for i in xrange(1, t+1):

    n = int(raw_input())
    if n == 1:
        l = [raw_input()]
    else:
        l = raw_input().split()

    a = {}
    for k in A1:
        a[k] = None

    res = solve('', a, l)

    print 'Case #%d:' % (i), res
