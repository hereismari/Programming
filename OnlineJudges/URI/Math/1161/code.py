
l = [1] * 30
for i in xrange(2,30):
    l[i] = l[i-1] * i

while True:
    try:
        m, n = map(int,raw_input().split())
    except:
        break
    
    print l[m] + l[n]
