n, m = map(int,raw_input().split())
l = map(int,raw_input().split())

answer = 0
for i in xrange(m):
	x,y = map(int,raw_input().split())
	answer += min(l[x-1],l[y-1])

print answer
