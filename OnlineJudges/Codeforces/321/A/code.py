n = int(raw_input())

ans = 1
max_v = 0
cont = 0

num = map(int, raw_input().split())
for e in num:
    if e < max_v:
        max_v = e
        cont = 1
    else:
        max_v = e
        cont += 1
        ans = max(ans, cont)

print ans
