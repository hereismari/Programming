import math
n = int(raw_input())
for i in xrange(n):
    x,y = map(int,raw_input().split())
    area = int(math.floor((x*y)/2.0))
    print str(area) + ' cm2'
