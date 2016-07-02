n, a, b = map(int, raw_input().split())

ans = (a + b) % n
if ans == 0: ans = n

    print ans
