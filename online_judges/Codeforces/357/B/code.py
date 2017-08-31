n = int(raw_input())

a = 1234567
b = 123456
c = 1234

i = 0
j = 0

flag = (n % c == 0 or n % a == 0 or n % b == 0)
while True:

    j = 0
    if i*a > n or flag: break
    while True:
        if i*a + j*b > n or flag: break
        if (n - (i*a + j*b)) % c == 0:
            flag = True
            break
        j += 1
    i += 1

if flag: print "YES"
else: print "NO"
