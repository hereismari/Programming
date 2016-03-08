while True:

    x = int(raw_input())
    if x == 0: break
    i = (x-3)*2 + 3
    print i
    ans =  (i - x)/(1.0*x)
    print "%.6f" % ans
