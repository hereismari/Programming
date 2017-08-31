n = int(raw_input())
s = raw_input()

li = map(int, raw_input().split())

ans = -1

l = -1
r = -1

for i in xrange(n):
    if s[i] == 'R': 
        r = i
    if s[i] == 'L':
        l = i

    if l != -1 and r != -1 and r < l:
        if ans == -1: ans = (li[l] - li[r])/2
        ans = min(ans, (li[l] - li[r])/2)

print ans
