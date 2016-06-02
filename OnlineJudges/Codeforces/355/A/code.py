n, m = map(int, raw_input().split())
l = map(int, raw_input().split())

ans = n
for e in l:
    if e > m:
        ans += 1

print ans
