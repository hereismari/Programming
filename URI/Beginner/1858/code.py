n = int(raw_input())
l = map(int,raw_input().split())

index = 1
ans = l[0]
for i in xrange(n):
	if l[i] < ans:
		index = i + 1
		ans = l[i]

print index
