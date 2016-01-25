n = int(raw_input())

ans = 2
x = n - 1

for i in xrange(n/2 - 1):
    print x
    ans += 2 * x
    x += 2 ** ((n-3)/2)

ans += x
print x/(ans *1.0) * 100
