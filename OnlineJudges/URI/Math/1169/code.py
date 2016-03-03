n = int(raw_input())
for i in xrange(n):
    x = int(raw_input())
    aux = 1
    for j in xrange(x):
        aux *= 2
    print str((aux/12)/1000) + ' kg'

