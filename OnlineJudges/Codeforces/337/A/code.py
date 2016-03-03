n = int(raw_input())

ans = n/4
if (n/2) % 2 == 0: ans -= 1
if n % 2 == 1: ans = 0
print ans
