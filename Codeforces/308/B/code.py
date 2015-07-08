s = raw_input()
n = int(s)

answer = 10 + len(s) - 1
i = 10
k = 2
while i <= 1000000000 and n >= 10:

	if(n >= i):
		answer += (n-i) * k
		break
	else:
		answer += k*(i+1)	
	i *= 10
	k += 1
	

if n <= 10: print n
else: print answer
