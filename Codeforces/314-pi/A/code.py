n = int(raw_input())
l = map(long,raw_input().split())
first = l[0]
last = l[n-1]
print abs(l[1] - l[0]), abs(last - first)
for i in xrange(1,n-1):
    print min(abs(l[i+1]-l[i]),abs(l[i]-l[i-1])), max(abs(l[i]-first),abs(last-l[i]))
print abs(last - l[n-2]), abs(last - first)
    

