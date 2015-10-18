def verify(i):
    return i < n-1 and l[i-1] == 1 and l[i+1] == 1 and l[i] == 0

n = int(raw_input())
l = map(int, raw_input().split())

ans = 0
flag = False
for i in xrange(len(l)):
    
    if l[i] == 1:
        flag = True
    
    if flag and verify(i): ans += 1
    ans += l[i]

print ans
