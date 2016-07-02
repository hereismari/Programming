n = int(raw_input())


flag = False
for i in xrange(n):
    s, a, b = raw_input().split()

    if int(a) >= 2400 and int(b) - int(a) > 0:
        flag = True

if flag: print "YES"
else: print "NO"
