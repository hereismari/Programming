import random

t = int(raw_input())

A = 'QWERTYUIOPLKJHGFDSAZXCVBNM'

def solve(passwords):

    cont = 0

    a = list(A)

    while cont < 10000:

        random.shuffle(a)
        s = ''.join(a)

        flag = False
        for p in passwords:
            if p in s:
                cont += 1
                flag = True
                continue

        if not flag:
            return s

    return 'IMPOSSIBLE'

for i in xrange(1, t+1):

    n = int(raw_input())
    if n == 1:
        l = [raw_input()]
    else:
        l = raw_input().split()

    res = ''
    new_l = []
    for p in l:
        if len(p) == 1:
            res = 'IMPOSSIBLE'
        else:
            if len(set(p)) == len(p):
                new_l.append(p)

    if res == 'IMPOSSIBLE':
        print 'Case #%d:' % (i), res
        continue

    res = solve(new_l)
    print 'Case #%d:' % (i), res
