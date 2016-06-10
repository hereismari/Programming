n, m = map(int, raw_input().split())
l = map(int, raw_input().split())

m -= 1

ans = l[m]
i = 1

while m-i >= 0 or m+i <= n-1:
    if m-i < 0 and m+i <= n-1: ans += l[m+i]
    elif m+i > n-1 and m-i >= 0: ans += l[m-i]
    else:
        if l[m-i] == 1 and l[m+i] == 1: ans += 2

    i += 1
print ans
