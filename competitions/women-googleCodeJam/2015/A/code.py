t = int(raw_input())

for k in xrange(1, t+1):

    n = int(raw_input())

    s = raw_input()

    res = ''

    aux = ''
    for i in xrange(len(s)):
        if s[i] == 'I':
            aux += '1'
        else:
            aux += '0'
        if i % 8 == 7:
            res += chr(int(aux, 2))
            aux = ''

    print 'Case #%d:' % (k), res
