def compare(x, y):
    if x[0] < y[0]: return -1
    elif x[0] > y[0]: return 1
    else:
        if x[1] > y[1]: return -1
        else: return 1

cont = 0

while True:

    cont += 1

    try:
        n = int(raw_input())
    except:
        break

    p = map(float, raw_input().split())
    p = [(p[y], str(y)) for y in xrange(10)]
    p = sorted(p, cmp=compare, reverse=True)

    print 'Caso %d:' % cont,
    ans = ''
    for i in xrange(n): ans += p[i][1]
    print ans
