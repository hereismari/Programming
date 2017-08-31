from random import randint

name = 'abcdefghijkl'

for e in name:

    input_name = 'io/%s.in' % e

    print 'generating %s' % e
    f = open(input_name, 'w+')

    x = randint(1, 1000)
    y = randint(1, 1000)
    n = randint(1, 1000000)

    f.write('%d %d %d\n' % (x, y, n))

    for i in xrange(n):
        x = randint(1, 1000)
        y = randint(1, 1000)
        t = randint(1, 1000000)
        f.write('%d %d %d\n' % (x, y, t))
