n = int(raw_input())
l = map(int, raw_input().split())

ans = 0
for e in l:

    ans += e - 1

    if ans > 0 and ans % 2:
        print 1
    else:
        print 2
