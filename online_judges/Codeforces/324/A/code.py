n, t = map(int , raw_input().split())

if n == 1 and t == 10:
    print -1
else:
    if t == 10: n -= 1
    ans = str(t)
    while n > 1:
        ans += '0'
        n -= 1
    print ans
