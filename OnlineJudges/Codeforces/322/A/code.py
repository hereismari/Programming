n, m = map(int, raw_input().split())

ans1 = min(n, m)
ans2 = max(m-ans1, n-ans1)
if ans2 % 2 == 1: ans2 -= 1
print ans1, ans2/2
