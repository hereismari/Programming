n = int(raw_input())
l = map(int,raw_input().split())

l.sort()

answer = 0
for i in range(1,len(l)):
	if(l[i] <= l[i-1]):
		answer += l[i-1] - l[i] + 1
		l[i] += l[i-1] - l[i] + 1

print answer
