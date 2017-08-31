t, s, x = map(int, raw_input().split())

if x < t: print "NO"
else:

    x -= t
    if (x % s == 0 or x % s == 1) and (x >= s or x == 0): print "YES"
    else: print "NO"
