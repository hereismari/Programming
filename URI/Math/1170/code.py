import math

n = int(raw_input())
for i in xrange(n):
    x = float(raw_input())
    print int(math.ceil(math.log(x,2))),
    print 'dias'
