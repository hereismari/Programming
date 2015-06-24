n = int(raw_input())

l = map(int,raw_input().split())

answer = 0
for i in range(2,len(l)):
	answer = max(answer,l[i]-l[i-2])

print answer 
