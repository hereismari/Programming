l = map(int,raw_input().split())
ans = 0
ans = max(min(l[0] + l[2],min(l[1],l[3])),ans)
ans = max(min(l[1] + l[3],min(l[0],l[2])),ans)
ans = max(min(l[0] + l[3],min(l[2],l[1])),ans)
ans = max(min(l[1] + l[2],min(l[0],l[3])),ans)

print ans*ans
