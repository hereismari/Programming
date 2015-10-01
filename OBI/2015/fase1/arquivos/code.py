n,b = map(int,raw_input().split())
l = map(int,raw_input().split())

l.sort()

i = 0
j = n-1

answer = 0
while i <= j:
	if (l[j] + l[i] > b):
		answer += 1
		j -= 1
	else:
		answer += 1
		j -= 1
		i += 1

print answer 
