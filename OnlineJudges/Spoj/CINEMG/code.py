from string import lower, upper
import re

n = int(raw_input())

for i in xrange(n):

    m, k = map(int, raw_input().split())
    words = re.split(' |-|:', raw_input())
    words = [lower(e) for e in words]
    
    for j in xrange(k):
        title = re.split(' |-|:', raw_input())
        first = True
        ans = ''
        for e in title:
            if e == '': continue
            if lower(e) in words and not first:
                ans += lower(e[0])
            elif not lower(e) in words:
                ans += upper(e[0])
            first = False
        print ans
    print

