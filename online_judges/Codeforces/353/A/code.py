a = map(int, raw_input().split())

if a[2] < 0:
    a[0] = -a[0]
    a[1] = -a[1]

if a[2] != 0 and a[0] < a[1]:
    if abs(a[1]-a[0]) % abs(a[2]) == 0:
        print "YES"
    else: 
        print "NO"
else: 
    if a[1]==a[0]:
        print "YES"
    else:
        print "NO"
