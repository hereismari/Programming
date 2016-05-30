a, b, c = map(int, raw_input().split())
if b == a: print "YES"
elif c == 0: print "NO"
elif c < 0 and b > a: print "NO"
elif c > 0 and b < a: print "NO"
else:
    if c == 1 and b > a: print "YES"
    elif c == -1 and b < a: print "YES"
    else:
        aux = a
        if b > a:
            while aux < b:
                aux += c
        elif b < a:
            while aux > b:
                aux += c
        
        print "YES" if aux == b else "NO"
